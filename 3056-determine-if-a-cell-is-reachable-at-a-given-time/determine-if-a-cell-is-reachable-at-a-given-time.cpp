class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy && t == 1) return false;
        int d = max(abs(fx-sx), abs(fy-sy));
        cout << d << ' ';
        if(d <= t) return true;
        else return false;
    }
};