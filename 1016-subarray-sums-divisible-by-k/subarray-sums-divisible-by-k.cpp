class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //TC: O(n^3)

        // int n = nums.size();
        // int ans = 0;

        // for(int i = 0; i < n; i++){
        //     for(int j= i; j < n; j++){
        //         int sum =0;
        //         for(int k = i; k <= j; k++){
        //             sum += nums[k];
        //         }
        //         if(sum%k == 0) ans++;
        //     }
        // }
        // return ans;

        //TC: O(n^2)

        // int n = nums.size();
        // int ans = 0;

        // for(int i = 0; i < n; i++){
        //     int sum =0;
        //     for(int j = i; j < n; j++){
        //         sum += nums[j];
        //         if(sum%k == 0) ans++;
        //     }
        // }
        // return ans;
        
        //TC: O(n)

        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            int rem = sum % k;
            if(rem < 0){
                rem += k;
            }
            if(mp.find(rem) != mp.end()){
                ans  += mp[rem];
            }

            mp[rem]++;
        }
        return ans;
    }
};