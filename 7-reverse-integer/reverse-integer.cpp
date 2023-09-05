class Solution {
public:
    int reverse(int x) {
        long revNum = 0;
        long flag = 1;
        if(x < 0){
            flag = -1;
            x = x*flag;
        }
        while(x > 0){
            int rem = x%10;
            revNum = revNum*10 + rem;
            x /= 10;
        }
        revNum = revNum * flag;
        if(revNum > INT_MAX || revNum < INT_MIN) return 0;
        return revNum;
    }
};