class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }
        
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = cols-1, top = 0, bottom = rows-1;
        
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
            
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return result;
    }
};


// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<int> ans;
//         int i = 0;
//         int j = 0;
//         int dr[] = {0, 1, 0, -1};
//         int dc[] = {1, 0, -1, 0};

//         vector<vector<int>> visited(m, vector<int>(n,0));
//         // if(m == 0) return ans;
//         visited[0][0] = 1;
//         ans.push_back(matrix[0][0]);

//         int index = 0;
//         int count = 1;
        
//         while(count < m*n){
//             int r = i + dr[index];
//             int c = j + dc[index];

//             if(r < m && c < n && r >= 0 && c >=0 && !visited[r][c]){
//                 count++;
//                 ans.push_back(matrix[r][c]);
//                 visited[r][c] = 1;
//                 i = r;
//                 j = c;
//             }
//             else{
//                 index = (index+1) % 4;
//             }
//         }
         
//         return ans;
//     }
// };