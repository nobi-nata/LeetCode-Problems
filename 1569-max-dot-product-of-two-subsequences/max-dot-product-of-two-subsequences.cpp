class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
        
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         dp[i][j] = max(nums1[i - 1] * nums2[j - 1] + max(dp[i - 1][j - 1], 0),
        //                       max(dp[i - 1][j], dp[i][j - 1]));
        //     }
        // }
        
        // return dp[n][m];

        std::vector<int> current(n + 1, INT_MIN), previous(n + 1, INT_MIN);
         for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int curr_product = nums1[i-1] * nums2[j-1];
                current[j] = std::max({curr_product, previous[j], current[j-1], curr_product + std::max(0, previous[j-1])});
            }
            std::swap(current, previous);
        }
        return previous[n];

    }
};