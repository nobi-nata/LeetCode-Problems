class Solution {
public:
    // int count(int i, vector<int> dp){
    //     if(i >= 0){
    //         return 0;
    //     }
    //     if(dp[i] != -1) return dp[i];
    //     return dp[i] = count(i-1,dp);
    // }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            if(i == 1) dp[i] = dp[i-1];
            else dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};