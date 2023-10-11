class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //TC: O(n^2)

        // int n = nums.size();
        // for(int i = 0; i < n ; i++){
        //     for(int j = i+1; j < n; j++){
        //         if(nums[i]+nums[j] == target){
        //             return {i, j};
        //         }
        //     }
        // }
        // return {0, 0};

        //TC: O(nlogn) + SC: O(n)

        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n-1;

        while(i < j){
            if(nums[i] + nums[j] == target){
                if(nums[i] == nums[j]) return {mp[nums[i]][0], mp[nums[j]][1]};
                else return {mp[nums[i]][0], mp[nums[j]][0]};
            }
            else if(nums[i] + nums[j] > target) j--;
            else i++;
        }
        return {0,0};
    }
};