class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    int flag;
public:
    FooBar(int n) {
        this->n = n;
        flag = 0;
        // m2.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            while(flag == 1){
                cv.wait(lock);
            }
            
            // m1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            flag = 1;
            cv.notify_all();
            // m2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            while(flag == 0){
                cv.wait(lock);
            }
            // m2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            flag = 0;
            cv.notify_all();
            // m1.unlock();
        }
    }
};