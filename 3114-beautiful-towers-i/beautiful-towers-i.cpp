class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        
        long long ans = 0;
        
        for(int i = 0; i < maxHeights.size(); i++){
            long long sum = 0;
            int num = INT_MAX;
            for(int j = i; j >= 0; j--){
                num = min(num, maxHeights[j]);
                sum += num;
            }
            num = INT_MAX;
            for(int j = i+1; j < maxHeights.size(); j++){
                num = min(num, maxHeights[j]);
                sum += num;
            }
            ans = max(sum, ans);
        }
        
        return ans;
        
    }
};