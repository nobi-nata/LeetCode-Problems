class Solution {
public:
    int solve(vector<int> &cost, vector<int> &time, int i, int bank, vector<vector<int>> &dp){
        if(bank <= 0) return 0;
        if(i >= time.size()) return 1e9;
        if(dp[i][bank] != -1) return dp[i][bank];
        
        int nottake = solve(cost, time, i+1, bank, dp);
        int take = cost[i] + solve(cost, time, i+1, bank - time[i] - 1, dp);
        return dp[i][bank] = min(nottake, take);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        // int ans = 0;

        // vector<pair<int, int>> vec;

        // for(int i = 0; i < cost.size(); i++){
        //     vec.push_back({cost[i], time[i]});
        // }

        // sort(vec.begin(), vec.end());

        // int i = 0;
        // int j = cost.size()-1;

        // while(i <= j){
        //     ans += vec[i].first;
        //     j = j - vec[i].second;
        //     i++;
        // }
        // return ans;


        vector<vector<int>> dp(501, vector<int> (501, -1));
        return solve(cost, time, 0, time.size(), dp);
    }
};