class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c, int n, int m){
        vis[r][c] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1,0, -1};
        int cnt = grid[r][c];
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] > 0){
                cnt += dfs(grid, vis, nr, nc, n , m);
            }
        }
        return cnt;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] > 0){
                    cnt = max(cnt, dfs(grid, vis, i, j, n, m));
                }
            }
        }
        return cnt;
    }
};