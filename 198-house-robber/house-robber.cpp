class Solution {
public:
    // int robb(vector<int> nums, int i, int n){
    //     if(i >= n){
    //         return 0;
    //     }
    //     int pik = nums[i] + robb(nums, i+2, n);
    //     int notpik = robb(nums, i+1, n);
    //     return max(pik, notpik);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            if(i > 1) dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
            else dp[i] = max(nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};