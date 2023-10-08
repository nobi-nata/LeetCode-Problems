class Solution {
public:
    int bs(vector<int> nums, int s, int e){
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] == 0) return mid;
            else if(nums[mid] > 0) e = mid-1;
            else s = mid+1;
        }
        return s;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        //nlog(n)

        // for(int i = 0; i < nums.size(); i++){
        //     nums[i] *= nums[i];
        // }
        // sort(nums.begin(), nums.end());
        // return nums;

        //O(log(n)+n);

        int n = nums.size();
        int i = 0;
        int j = n-1;
        j = bs(nums, i, j);
        i = j-1;
        vector<int> ans(n, 0);
        for(int k = 0; k < n; k++){
            int c1 = 1e9, c2 = 1e9;
            if(i >= 0) c1 = nums[i]*nums[i];
            if(j < n) c2 = nums[j]*nums[j];

            if(c1 > c2){
                ans[k] = c2;
                j++;
            }
            else{
                ans[k] = c1;
                i--;
            }
        }
        return ans;

        //o(n);

        // int n = nums.size();
        // int i = 0;
        // int j = n-1;
        // vector<int> ans(n, 0);
        // for(int k = n-1; k >= 0; k--){
        //     int c1 = nums[i]*nums[i];
        //     int c2 = nums[j]*nums[j];

        //     if(c1 > c2){
        //         ans[k] = c1;
        //         i++;
        //     }
        //     else{
        //         ans[k] = c2;
        //         j--;
        //     }
        // }
        // return ans;
    }
};