class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //TC : O(n^3);
        // int n = nums.size();
        // int ans = INT_MIN;
        // for(int i = 0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         int sum = 0;
        //         for(int k = i; k <= j; k++){
        //             sum += nums[k];
        //         }
        //         ans = max(ans, sum);
        //     }
        // }
        // return ans;


        //TC : O(n^2);
        // int n = nums.size();
        // int ans = INT_MIN;
        // for(int i = 0; i < n; i++){
        //     int sum = 0;
        //     for(int j = i; j < n; j++){
        //         sum += nums[j];
        //         ans = max(ans, sum);
        //     }
        // }
        // return ans;


        //TC : O(n);
        int n = nums.size();
        int ans = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(sum < 0) sum = 0;
            sum += nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};