class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();

        if(r == n && c == m) return mat;
        if(m*n != r*c) return mat;

        vector<vector<int>> ans(r, vector<int>(c, 0));

        int x = 0, y = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(y < c){
                    ans[x][y] = mat[i][j];
                }
                else{
                    y = 0;
                    x++;
                    ans[x][y] = mat[i][j];
                }
                y++;
            }
        }
        return ans;
    }
};