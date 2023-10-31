class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target) return mid;
            //left arr
            if(nums[mid] >= nums[l]){
                if(nums[l] <= target && nums[mid] > target){
                    r = mid - 1;
                }
                else{
                    l = mid+1;
                }
            }
            //right arr
            else{
                if(nums[r] >= target && nums[mid] < target){
                    l = mid + 1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};