class Solution {
public:
    bool dfs(vector<vector<char>> &board, vector<vector<int>> &vis, string word, int r, int c,int ind){
        int m = board.size();
        int n = board[0].size();
        if(ind == word.size()) return true;
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n){
                if(board[nr][nc] == word[ind]){
                    if(!vis[nr][nc]){
                        vis[nr][nc]=1;
                        if(dfs(board, vis, word, nr, nc, ind+1)) return true;
                        vis[nr][nc]=0;
                    }
                }
            } 
        }
       
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                    if(dfs(board, vis, word, i, j, 1)){
                        return true;
                    }
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};