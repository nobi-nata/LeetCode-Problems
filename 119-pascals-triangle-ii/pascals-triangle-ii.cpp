class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int> dp;
      dp.push_back({1});
      for(int i=1;i<=rowIndex;i++){
        vector<int> currvect;
        currvect.push_back(1);
        for(int i=1;i<dp.size();i++){
            currvect.push_back(dp[i-1]+dp[i]);
        }
        currvect.push_back(1);
        dp = currvect;
      }
      return dp;

    }
};