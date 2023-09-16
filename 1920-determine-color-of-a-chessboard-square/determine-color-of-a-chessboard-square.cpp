class Solution {
public:
    bool squareIsWhite(string c) {
        int n = c[0] - 'a';
        int m = c[1] - '1';
        if((n+m)%2 == 0){
            return false;
        }
        return true;
    }
};