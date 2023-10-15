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

    void recur(vector<string> b, int n, int &cnt, int r){
        if(r == n){
            cnt++;
            return;
        }

        for(int c = 0; c < n; c++){
            if(isSafe(b, n, c, r)){
                b[r][c] = 'Q';
                recur(b, n, cnt, r+1);
                b[r][c] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        int cnt = 0;
        string x = "";
        for(int i = 0; i < n; i++) x += '.';
        vector<string> b(n, x);

        recur(b, n, cnt, 0);

        return cnt;
    }
};