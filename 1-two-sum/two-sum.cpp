class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int k = (target - nums[i]);
                if( k == nums[j]){
                    return {i , j};
                    // cout << 'hi';
                }
            }
        }
        return {0,0};
    }
};