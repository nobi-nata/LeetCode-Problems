class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n+1, 1e9);
        int first = 0;
        int second = cost[0];
        
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(i == n) return min(second, first);
            int temp = second;
            second = min(second, first) + cost[i]; 
            first = temp;
        }
        return second;
    }
};