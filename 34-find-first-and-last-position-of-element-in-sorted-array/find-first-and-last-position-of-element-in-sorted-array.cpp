class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //TC: O(n);
        
        // int n = nums.size();
        // vector<int> ans;
        // for(int i = 0; i < n; i++){
        //     if(nums[i] == target && ans.size() == 0) ans = {i, i};
        //     else if(nums[i] == target) ans[1] = i;
        // }
        // if(ans.size() == 0) return {-1, -1};
        // return ans;

        //TC: O(n);

        int n = nums.size();
        int s = 0, e = n-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] >= target) e = mid-1;
            else s = mid+1;
        }
        vector<int> ans;
        if(s >= n) return {-1, -1};
        else if(nums[s] != target) return {-1, -1};
        else ans = {s, s};

        s = 0, e = n-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] > target) e = mid-1;
            else s = mid+1;
        }
        ans[1] = e;
        return ans;
        
    }
};