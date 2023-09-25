class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        for(int i = 0; i < m-2; i++){
            for(int j = 0; j < n-2; j++){
                int s = 0;
                for(int k = j; k < j+3; k++){
                    s += grid[i][k];
                    s += grid[i+2][k];
                }
                s += grid[i+1][j+1];
                ans = max(ans, s);
            }
        }
        return ans;
    }
};