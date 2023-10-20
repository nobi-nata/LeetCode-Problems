class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;

        int curr = 0, tar, n = stations.size();
        int ans = 0;

        if(fuel >= target) return 0;

        if(n == 0 || fuel < stations[0][0]) return -1;

        for(int i = 0; i < n; i++){
            fuel += curr - stations[i][0];
            pq.push(stations[i][1]);
            curr = stations[i][0];

            if(i == n-1){
                tar = target - curr;
            }
            else{
                tar = stations[i+1][0] - curr;
            }

            while(!pq.empty() && fuel < tar){
                fuel += pq.top();
                pq.pop();
                ans++;
            }

            if(fuel < tar) return -1;
        }
        return ans;
    }
};