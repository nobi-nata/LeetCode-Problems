class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int flag = 0;
        if(nums[0] <= nums[nums.size()-1]) flag = 1;
        for(int i = 0; i < nums.size()-1; i++){
            if(flag && nums[i] > nums[i+1]) return false;
            if(!flag && nums[i] < nums[i+1]) return false;
        }
        return true;
    }
};