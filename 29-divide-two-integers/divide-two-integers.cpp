class Solution {
public:
    int divide(int dividend, int divisor) {
        long n1 = (long)dividend;
        long n2 = (long)divisor;
        int sign = 1;
        if(n1 < 0){
            sign *= -1;
            n1 *= -1;
        }
        if(n2 < 0){
            sign *= -1;
            n2 *= -1;
        }

        long quo = 0;

        while(n1 >= n2){
            long temp = n2, mul = 1;
            while(temp << 1 <= n1){
                temp <<= 1;
                mul <<= 1;
            }
            n1 -= temp;
            quo += mul;
        }
        quo = quo*sign;
        if(quo < INT_MIN) return INT_MIN;
        if(quo > INT_MAX) return INT_MAX;

        return (int)quo;
    }
};