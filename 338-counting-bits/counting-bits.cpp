class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int j = i;
            int cnt = 0;
            while(j){
                if(j&1) cnt++;
                j = j>>1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};