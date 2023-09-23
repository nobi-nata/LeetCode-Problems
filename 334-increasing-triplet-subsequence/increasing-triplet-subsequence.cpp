class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // if(nums.size() < 3) return false;
        // for(int i = 0; i < nums.size() - 2; i++){
        //     for(int j = i+1; j < nums.size() - 1; j++){
        //         for(int k = j+1; k < nums.size(); k++){
        //             if(nums[i] < nums[j] && nums[j] < nums[k]) return true;
        //         }
        //     }
        // }
        // return false;

        if(nums.size()<3)return false;
        int left = INT_MAX;
        int mid = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > mid) return true;
            else if (nums[i] > left && nums[i] < mid)
            {
                mid = nums[i];
            }
            else if(nums[i] < left )
            {
                left = nums[i];
            }
        }
        return false;


    }
};