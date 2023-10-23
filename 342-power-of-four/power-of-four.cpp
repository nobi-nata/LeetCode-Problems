class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n%4 || n == INT_MIN){
            cout <<'-';
            if(n == 1) return true;
            return false;
        }
        else{
            
            if(n < 0) return false;
            int ele = n;
            while(ele > 4 && ele%4 == 0){
                ele /= 4;
            }
            if(ele == 4) return true;
        }
        return false;
    }
};