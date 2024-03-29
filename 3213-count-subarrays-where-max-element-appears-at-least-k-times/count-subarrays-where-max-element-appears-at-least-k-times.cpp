class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        int max_num = *max_element(nums.begin(), nums.end());
        long long l = 0, r = 0, ans = 0;
        while(r < n){
            if(nums[r] == max_num) count++;

            while(count >= k){
                if(nums[l] == max_num) count--;
                l++;
                ans += n - r;
            }
            r++;
        }
        return ans;
    }
};