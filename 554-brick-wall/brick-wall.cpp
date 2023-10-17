class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;

        int n = wall.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < wall[i].size()-1; j++){
                sum += wall[i][j];
                mp[sum]++;
                ans = max(ans, mp[sum]);
            }
        }
        return n - ans;
    }
};