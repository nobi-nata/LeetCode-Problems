class Solution {
public:

    int cnt(vector<int>& nums, int target, vector<int> &dp){
        
        if(target == 0) return 1;
        if(target < 0) return 0;
        
        if(dp[target] != -1) return dp[target];

        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            count += cnt(nums, target - n, dp);
        }

        return dp[target] = count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(1001, -1);
        return cnt(nums, target, dp);
    }
};