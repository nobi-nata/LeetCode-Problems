class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] == target && ans.size() == 0) ans = {i, i};
            else if(nums[i] == target) ans[1] = i;
        }
        if(ans.size() == 0) return {-1, -1};
        return ans;
    }
};