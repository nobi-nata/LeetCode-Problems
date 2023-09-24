// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size();
//         int i = 0;
//         int cnt = 0;
//         int ans = 0;
//         unordered_map<int, int> mp;
//         while(i < n){
//             cnt += nums[i];
//             if(cnt == goal) ans++;
//             if(mp.find(cnt-goal) != mp.end()){
//                 ans += mp[cnt-goal];
//             }
//             mp[cnt]++;
//             i++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int helper(vector<int> nums, int goal){
        int n = nums.size(), i = 0, j = 0, sum = 0, cnt = 0;

        while(j < n){
            sum += nums[j];
            while(i <= j && sum > goal){
                sum -= nums[i];
                i++;
            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal-1);
    }
};