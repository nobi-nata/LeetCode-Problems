class ZeroEvenOdd {
private:
    int n;
    int num;
    mutex m;
    condition_variable cv;
    int flag;


public:
    ZeroEvenOdd(int n) {
        this->n = n;
        flag = 0;
        num = 1;

    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(num <= n){
            unique_lock<mutex> lock(m);
            while(flag != 0  && num <= n){
                cv.wait(lock);
            }
            if(num <= n)
                printNumber(0);
            flag = (num%2) == 0 ? 2 : 1;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(num <= n){
            unique_lock<mutex> lock(m);
            while(flag != 2  && num <= n){
                cv.wait(lock);
            }
            if(num <= n)
                printNumber(num++);
            flag = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(num <= n){
            unique_lock<mutex> lock(m);
            while(flag != 1 && num <= n){
                cv.wait(lock);
            }
            if(num <= n)
                printNumber(num++);
            flag = 0;
            cv.notify_all();
        }
    }
};