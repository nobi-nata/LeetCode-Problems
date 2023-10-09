class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //TC: O(n^2);

        // int n = nums.size();
        // vector<int> ans;
        // for(int i= 0; i < n; i++){
        //     int cnt = 0;
        //     for(int j = 0; j < n; j++){
        //         if(nums[i] == nums[j]) cnt++;
        //     }
        //     if(cnt > n/3){
        //         if(ans.size() == 0) ans.push_back(nums[i]);
        //         else if(ans.back() != nums[i]) ans.push_back(nums[i]);
        //     } 
        //     if(ans.size() > 1) return ans;
        // }
        // return ans;
        
        //TC: O(n) + SC: O(n);

        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i : nums){
            mp[i]++;
            if(mp[i] > n/3){ 
                if(ans.size() == 0) ans.push_back(i);
                else if(ans.back() != i) ans.push_back(i);
            }
            if(ans.size() > 1) return ans;
        }
        return ans;
        
        // int ele = nums[0];
        // int freq = 1;
        // int ele1 = nums[0];
        // int freq1 = 0;

        // for(int i = 1; i < nums.size(); i++){
        //     if(freq1 == 0 && ele != nums[i]){
        //         ele1 = nums[i];
        //         freq1 = 1;
        //     }
        //     else if(freq == 0 && ele1 != nums[i]){
        //         ele = nums[i];
        //         freq = 1;
        //     }
        //     else if(ele == nums[i]){
        //         freq++;
        //     }
        //     else if(ele1 == nums[i]){
        //         freq1++;
        //     }
        //     else{
        //         freq--;
        //         freq1--;
        //     }
            
        // }
        // int cnt = 0, cnt1 = 0;
        // for(auto i : nums){
        //     if(i == ele) cnt++;
        //     if(i == ele1) cnt1++;
        // }
        // if(cnt > nums.size()/3 && freq && freq1 && cnt1 > nums.size()/3){
        //     return {ele, ele1};
        // }
        // if(cnt > nums.size()/3 && freq){
        //     return {ele};
        // }
        // if(cnt1 > nums.size()/3 && freq1){
        //     return {ele1};
        // }
        // return {};
    }
};