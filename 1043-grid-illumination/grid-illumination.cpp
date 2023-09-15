class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<long,long> mp1;
        unordered_map<long,long> mp2;
        unordered_map<long,long> mp3;
        unordered_map<long,long> mp4;
        unordered_map<long,long> mp5;

        for(int i = 0; i < lamps.size(); i++){
            int x = lamps[i][0];
            int y = lamps[i][1];
            long val = (long)x*n+y;
            mp1[x]++;
            mp2[y]++;
            mp3[x-y]++;
            mp4[x+y]++;
            mp5[val]++;
        }

        vector<int> ans(queries.size(), 0);
        int dirs[][2]  = {{1,0},{1, -1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{0,0}};

        for(int i = 0; i < queries.size(); i++){
            int x = queries[i][0];
            int y = queries[i][1];
            

            if(mp1[x] > 0 || mp2[y] > 0 || mp3[x-y] > 0 || mp4[x+y] > 0){
                ans[i] = 1;
            }
            else ans[i] = 0;


            for(auto dir : dirs){
                int x1 = x + dir[0];
                int y1 = y + dir[1];
                long val = (long)x1*n+y1;
                if(x1>=0 && y1>=0 && x1< n && y1<n && mp5.find(val) != mp5.end()){
                    int time = mp5[val];

                    if(mp1[x1] > 0) mp1[x1]=mp1[x1]-time;
                    if(mp2[y1] > 0) mp2[y1]=mp2[y1]-time;
                    if(mp3[x1-y1] > 0) mp3[x1-y1]=mp3[x1-y1]-time;
                    if(mp4[x1+y1] > 0) mp4[x1+y1]=mp4[x1+y1]-time;
                    mp5.erase(x1*n+y1);
                }

            }
        }
        return ans;
    }
};