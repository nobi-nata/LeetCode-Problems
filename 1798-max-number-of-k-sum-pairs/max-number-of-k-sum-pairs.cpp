class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // int i = 0;
        // int j = nums.size() - 1;
        // int ans = 0;
        // while(i < j){
        //     if(nums[i] + nums[j] == k){
        //         i++;
        //         j--;
        //         ans++;
        //     }
        //     else if(nums[i] + nums[j] < k){
        //         i++;
        //     }
        //     else{
        //         j--;
        //     }
        // }
        // return ans;


        unordered_map<int, int> mp;
        int ans= 0;
        for(int i : nums){
            if(mp[k-i] > 0){
                mp[k-i]--;
                ans++;
            }
            else{
                mp[i]++;
            }

        }
        return ans;
    }
};