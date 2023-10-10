class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        //TC: O(n^3)

        // int n = nums.size();
        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         int maxi = nums[i];
        //         for(int k = i; k <= j ; k++){
        //             maxi = max(maxi, nums[k]);
        //         }
        //         if(maxi >= left && maxi <= right) ans++;
        //     }
        // }
        // return ans;

        //TC: O(n^2)

        // int n = nums.size();
        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     int maxi = nums[i];
        //     for(int j = i; j < n; j++){
        //         maxi = max(maxi, nums[j]);
        //         if(maxi >= left && maxi <= right) ans++; 
        //     }
        // }
        // return ans;

        //TC: O(n) + SC: O(n) -- DP

        // int n = nums.size();
        // vector<int> dp(n, 0);
        // int j = 0;
        // for(int i = 0; i < n ; i++){
        //     if(nums[i] >= left && nums[i] <= right){
        //         dp[i] = i-j+1;
        //     }
        //     else if(nums[i] < left){
        //         if(i > 0) dp[i] = dp[i-1];
        //     }
        //     else{
        //         j = i+1;
        //     }
        // }
        // int ans = 0;
        // for(int i : dp){
        //     ans += i;
        // }
        // return ans;

        //TC: O(n) -- DP
        
        int n = nums.size();
        int j = 0;
        int ans = 0;
        int prevc = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] >= left && nums[i] <= right){
                ans += (i-j+1);
                prevc = (i-j+1);
            }
            else if(nums[i] < left){
                ans += prevc;
            }
            else{//nums[i] > right
                j = i+1;
                prevc = 0;
            }
        }
        return ans;
    }
};