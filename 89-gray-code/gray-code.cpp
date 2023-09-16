class Solution {
public:
    vector<int> grayCode(int n) {
        // vector<int> p = {0, 1};
        // n--;
        // int prod = 1;
        // while(n > 0){
        //     prod = prod*2;
        //     for(int i = p.size()-1; i >= 0; i--) p.push_back(p[i]+prod);
        //     n--;
        // }
        // return p;

        vector<int> ans(1<<n);

        for(int i = 0; i < (1<<n); i++){
            ans[i] = i^(i>>1);
        }
        return ans;
    }
};