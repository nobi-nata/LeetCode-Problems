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

        // int n = nums.size();
        // unordered_map<int, int> mp;
        // vector<int> ans;
        // for(int i : nums){
        //     mp[i]++;
        //     if(mp[i] > n/3){ 
        //         if(ans.size() == 0) ans.push_back(i);
        //         else if(ans.back() != i) ans.push_back(i);
        //     }
        //     if(ans.size() > 1) return ans;
        // }
        // return ans;

        //TC: O(n);
        
        int n = nums.size();
        int freq1 = 0;
        int freq2 = 0;
        int ele1 = nums[0];
        int ele2 = nums[0];

        for(int i = 0; i < n; i++){
            if(ele1 == nums[i]){
                freq1++;
            }
            else if(ele2 == nums[i]){
                freq2++;
            }
            else if(freq1 == 0){
                ele1 = nums[i];
                freq1 = 1;
            }
            else if(freq2 == 0){
                ele2 = nums[i];
                freq2 = 1;
            }
            else{
                freq1--;
                freq2--;
            }
        }
        if(ele1 == ele2) return {ele1};

        freq1 = 0;
        freq2 = 0;
        for(int i : nums){
            if(i == ele1) freq1++;
            if(i == ele2) freq2++;
        }
        vector<int> ans;
        if(freq1 > n/3) ans.push_back(ele1);
        if(freq2 > n/3) ans.push_back(ele2);
        return ans;
    }
};