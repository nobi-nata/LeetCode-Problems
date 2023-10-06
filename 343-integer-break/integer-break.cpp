class Solution {
public:
    int integerBreak(int n) {
        //  if (n <= 3) return n - 1;
        // int quotient = n / 3, remainder = n % 3;
        // if (remainder == 0) return pow(3, quotient);
        // if (remainder == 1) return pow(3, quotient - 1) * 4;
        // return pow(3, quotient) * 2;

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};