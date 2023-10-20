class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.rbegin(), nums.rend());
        // return nums[k-1];

        // priority_queue<int, vector<int> , greater<int>> pq;

        // for(int i = 0; i < nums.size(); i++){
        //     if(pq.size() < k){
        //         pq.push(nums[i]);
        //     }
        //     else if(nums[i] > pq.top()){
        //         pq.pop();
        //         pq.push(nums[i]);
        //     }
        // }
        // return pq.top();

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            mini = min(nums[i], mini);
            maxi = max(maxi, nums[i]);
        }

        vector<int> cnt(maxi-mini+1, 0);

        for(int i = 0; i < nums.size(); i++){
            cnt[nums[i] - mini] += 1;
        }
        int rem = k;
        for(int i = cnt.size()-1; i >= 0; i--){
            rem -= cnt[i];
            if(rem <= 0){
                return i+mini;
            }
        }
        return 0;

    }
};