class Solution {
public:
    bool isSafe(vector<string> b, int n, int c, int r){
        for(int i = 0; i != r; i++){
            if(b[i][c] == 'Q') return false;
        } 
        for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--){
            if(b[i][j] =='Q') return false;
        }
        for(int i = r-1, j = c+1; i >= 0 && j < n; i--, j++){
            if(b[i][j] =='Q') return false;
        }
        return true;
    }

    void recur(vector<string> b, int n, vector<vector<string>> &ans, int r){
        if(r == n){
            ans.push_back(b);
            return;
        }

        for(int c = 0; c < n; c++){
            if(isSafe(b, n, c, r)){
                b[r][c] = 'Q';
                recur(b, n, ans, r+1);
                b[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string x = "";
        for(int i = 0; i < n; i++) x += '.';
        vector<string> b(n, x);

        recur(b, n, ans, 0);

        return ans;
    }
};