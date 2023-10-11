class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<vector<int>>dp;
      dp.push_back({1});
      for(int i=1;i<=rowIndex;i++){
       vector<int>prevvectvec = dp[i-1];
        vector<int>currvect;
        currvect.push_back(1);
        for(int i=1;i<prevvectvec.size();i++){
            currvect.push_back(prevvectvec[i-1]+prevvectvec[i]);
        }
        currvect.push_back(1);
        dp.push_back(currvect);
      }
    return dp[rowIndex];
    
    }
};