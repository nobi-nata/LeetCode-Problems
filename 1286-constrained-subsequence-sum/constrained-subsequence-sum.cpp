class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // std::deque<int> dq;
        // for (int i = 0; i < nums.size(); ++i) {
        //     nums[i] += !dq.empty() ? nums[dq.front()] : 0;
            
        //     while (!dq.empty() && (i - dq.front() >= k || nums[i] >= nums[dq.back()])) {
        //         if (nums[i] >= nums[dq.back()]) dq.pop_back();
        //         else dq.pop_front();
        //     }
            
        //     if (nums[i] > 0) {
        //         dq.push_back(i);
        //     }
        // }
        // return *std::max_element(nums.begin(), nums.end());

        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> dp(n, 0);

        pq.push({nums[0], 0});
        int ans = nums[0];
        dp[0] = nums[0];

        for(int i = 1; i < nums.size(); i++){
            while(i - pq.top().second > k){
                pq.pop();
            }

            dp[i] = max(nums[i], nums[i] + pq.top().first);
            ans = max(ans, dp[i]);
            pq.push({dp[i], i});
        }
        return ans;
    }
};