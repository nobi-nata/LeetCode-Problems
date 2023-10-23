class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 0) return false;
        if(n == 1) return true;
        int ele = n;
        while(ele > 4 && ele%4 == 0){
            ele /= 4;
        }
        if(ele == 4) return true;
        
        return false;
    }
};