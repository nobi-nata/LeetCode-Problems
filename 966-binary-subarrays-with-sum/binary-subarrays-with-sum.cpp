class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i = 0;
        int cnt = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        while(i < n){
            cnt += nums[i];
            if(cnt == goal) ans++;
            if(mp.find(cnt-goal) != mp.end()){
                ans += mp[cnt-goal];
            }
            mp[cnt]++;
            i++;
        }
        return ans;
    }
};