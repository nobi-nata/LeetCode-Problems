class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for(auto r : wall){
            int prefix  = 0;

            for(int i = 0; i < r.size() - 1; i++){
                prefix += r[i];
                mp[prefix]++;
                ans = max(ans, mp[prefix]);
            }
        }
        return n - ans;
    }
};