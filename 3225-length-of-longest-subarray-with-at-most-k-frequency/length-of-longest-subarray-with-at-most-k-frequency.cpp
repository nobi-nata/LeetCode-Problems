class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 0;
        while(i < n){
            mp[nums[i]]++;
            while(j < i && mp[nums[i]] > k){
                mp[nums[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};