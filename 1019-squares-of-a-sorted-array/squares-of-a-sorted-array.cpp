class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //nlog(n)

        for(int i = 0; i < nums.size(); i++){
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;

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