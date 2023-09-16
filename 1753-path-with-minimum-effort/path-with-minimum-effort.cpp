class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> wt(n, vector<int>(m,1e9));
        wt[0][0] = 0;
        pq.push({0, {0,0}});

        int dr[] = {-1,0,1,0};
        int dc[] = {0, -1,0,1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int w = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            for(int i = 0; i < 4; i++){
                int nx = x + dr[i];
                int ny = y + dc[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m ){
                    int neffort =  max(w, abs(heights[nx][ny] - heights[x][y]));
                    if(wt[nx][ny] > neffort){
                        wt[nx][ny] = neffort;
                        pq.push({wt[nx][ny], {nx, ny}});
                    }
                    
                }
            }
        }
        return wt[n-1][m-1];
    }
};