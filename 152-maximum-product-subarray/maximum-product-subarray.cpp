class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prefix = 1;
        int suffix = 1;

        int n = nums.size();
        vector<int> ans(n , 0);

        for(int i = 0; i < n; i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            maxi = max(maxi, max(prefix, suffix));
        }

        return maxi;

    }
};