class Solution {
public:
    int hammingWeight(uint32_t n) {
        // string s = to_string(n);
        int cnt = 0;
        for(int i = 0; i < 32; i++){
            if(n & 1) cnt++;
            n >>= 1;
        }
        return cnt;
    }
};