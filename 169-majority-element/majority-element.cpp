class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //TC: O(n^2);

        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     int count = 0;
        //     for(int j = 0; j < n; j++){
        //         if(nums[j] == nums[i]) count++;
        //     }
        //     if(count > n/2) return nums[i];
        // }
        // return 0;

        //TC: O(n) + SC: O(n);

        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i : nums){
            mp[i]++;
            if(mp[i] > n/2) return i;
        }
        return 0;
        
        // int ele = nums[0];
        // int freq = 1;

        // for(int i = 1; i < nums.size(); i++){
        //     if(nums[i] != ele && freq){
        //         freq--;
        //     }
        //     else if(nums[i] == ele){
        //         freq++;
        //     }
        //     else{
        //         ele = nums[i];
        //         freq = 1;
        //     }
        // }
        // return ele;
    }
};