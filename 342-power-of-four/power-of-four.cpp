class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n < 0) return false;
        // if(n == 1) return true;
        // int ele = n;
        // while(ele > 4 && ele%4 == 0){
        //     ele /= 4;
        // }
        // if(ele == 4) return true;
        
        // return false;



        if (n > 0 && (n & (n - 1)) == 0) {
            int zero_count = 0;
            while (n > 1) {
                zero_count++;
                n >>= 1;
            }
            return zero_count % 2 == 0;
        }
        return false;
    }
};