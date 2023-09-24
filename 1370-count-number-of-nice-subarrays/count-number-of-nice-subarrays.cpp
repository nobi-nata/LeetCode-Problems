class Solution {
public:
    int helper(vector<int> nums, int k){
        int i = 0, j = 0, n = nums.size(), cnt = 0;
        int ans = 0;

        while(j < n){
            if(nums[j] % 2){
                cnt++;
            }
            while(i <= j && cnt > k){
                if(nums[i] % 2) cnt--;
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // int i = 0, j = 0, n = nums.size(), cnt = 0;
        // int ans = 0;
        // unordered_map<int, int> mp;
        // while(j < n){
        //     if(nums[j] % 2) cnt++;
            
        //     if(mp.find(cnt-k) != mp.end()){
        //         ans += mp[cnt-k];
        //     }
            
        //     if(cnt == k) ans++;
        //     mp[cnt]++;
        //     j++;
        // }
        // return ans;



        return helper(nums, k) - helper(nums, k-1);
    }
};