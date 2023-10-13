class Solution {
public:
    void per(vector<int> nums, vector<vector<int>> &ans, int ind){
        if(ind == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int i = ind; i < nums.size(); i++){
            swap(nums[i], nums[ind]);
            per(nums, ans, ind+1);
            swap(nums[i], nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        per(nums, ans, 0);
        return ans;
    }
};