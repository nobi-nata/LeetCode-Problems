class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        vector<vector<int>> visited(m, vector<int>(n,0));
        // if(m == 0) return ans;
        visited[0][0] = 1;
        ans.push_back(matrix[0][0]);

        int index = 0;
        int count = 1;
        
        while(count < m*n){
            int r = i + dr[index];
            int c = j + dc[index];

            if(r < m && c < n && r >= 0 && c >=0 && !visited[r][c]){
                count++;
                ans.push_back(matrix[r][c]);
                visited[r][c] = 1;
                i = r;
                j = c;
            }
            else{
                index = (index+1) % 4;
            }
        }
         
        return ans;
    }
};