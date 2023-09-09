class Solution {
public:

    int cnt(vector<int>& nums, int target, vector<int> &dp){
        // If the remaining target is 0, there's one valid combination.
        if(target == 0) return 1;
        // If the remaining target becomes negative, it's not possible to reach it.
        if(target < 0) return 0;
         // If the result for 'remainingTarget' is already computed, return it.
        if(dp[target] != -1) return dp[target];

        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            // recursively calculate combinations for the new target.
            count += cnt(nums, target - n, dp);
        }
        // Store and return the computed result.

        return dp[target] = count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target + 1, -1);
        return cnt(nums, target, dp);
    }
};