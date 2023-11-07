class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time(dist.size(), 0);

        for(int i = 0; i < dist.size(); i++){
            time[i] = dist[i]/speed[i];
            if(dist[i]%speed[i]) time[i]++;
        }

        sort(time.begin(), time.end());
        int cnt = 0;

        for(int i = 0; i < time.size(); i++){
            if(time[i] <= i) break;
            cnt++;
        }

        return cnt;
    }
};