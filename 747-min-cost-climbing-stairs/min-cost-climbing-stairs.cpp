class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        dp[1] = cost[0];
        
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(i == n) return min(dp[i], dp[i-1]);
            dp[i+1] = min(dp[i], dp[i-1]) + cost[i]; 
        }
        return dp[n];
    }
};