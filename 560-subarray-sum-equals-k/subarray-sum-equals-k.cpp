class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()){
                ans += mp[sum - k];
            }

            mp[sum]++;
        }
        return ans;

        // int n = nums.size();
        // int ans = 0;

        // for(int i = 0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         int sum = 0;
        //         for(int k = i; k <= j; k++){
        //             sum += nums[k];
        //         }
        //         if(sum == k) ans++;
        //     }
        // }
        // return ans;

        // int n = nums.size();
        // int ans = 0;

        // for(int i = 0; i < n; i++){
        //     int sum = 0;
        //     for(int j = i; j < n; j++){
        //         sum += nums[j];
        //         if(sum == k) ans++;
        //     }
        // }
        // return ans;

    
    }
};