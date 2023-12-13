class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    int flagr = 0, flagc = 0;
                    for(int k = 0; k < n; k++){
                        if(j != k && mat[i][k] == 1) flagr = 1;
                    }
                    for(int k = 0; k < m; k++){
                        if(i != k && mat[k][j] == 1) flagc = 1;
                    }
                    if(flagr == 0 && flagc == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};