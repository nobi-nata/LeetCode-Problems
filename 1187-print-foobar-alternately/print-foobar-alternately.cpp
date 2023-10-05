class FooBar {
private:
    int n;
    mutex m1, m2;
    // condition_variable cv;
    // int flag;
public:
    FooBar(int n) {
        this->n = n;
        // flag = 1;
        m2.lock();
    }

    void foo(function<void()> printFoo) {
        // unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            
            // while(flag == 0){
            //     cv.wait(lock);
            // }
            
            m1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            // flag = 0;
            // cv.notify_one();
            m2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        // unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            
            // while(flag == 1){
            //     cv.wait(lock);
            // }
            m2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            // flag = 0;
            // cv.notify_one();
            m1.unlock();
        }
    }
};