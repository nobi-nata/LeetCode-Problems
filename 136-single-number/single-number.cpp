class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // TC: O(n) SC: O(n)

        // unordered_map<int, int> mp;
        // for(int i = 0; i < nums.size(); i++){
        //     mp[nums[i]]++;
        // }
        // for(auto i : mp){
        //     if(i.second == 1) return i.first;
        // }
        // return 0;



        //TC: O(nlogn)
        
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // if(n == 1) return nums[0];
        // for(int i = 0; i < n; i++){
        //     if(i == 0){
        //         if(nums[i] != nums[i+1])
        //             return nums[i];}
        //     else if(i == n-1){
        //         if(nums[i] != nums[i-1])
        //             return nums[i];}
        //     else if(nums[i] != nums[i-1] && nums[i] != nums[i+1]) return nums[i];
        // }
        // return 0;

        //TC: O(n)
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans ^= nums[i];
        }
        return ans;
        

    }
};