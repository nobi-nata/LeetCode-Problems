class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        int cnt = 0;
        int ans = 0;
        while(j < n){
            if(nums[j] == 0) cnt++;

            while(i <= j && cnt > k){
                if(nums[i] == 0) cnt--;
                i++;
            }


            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};