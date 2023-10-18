class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //TC:O(n^3)

        // int n = nums.size();
        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     int cnt = 1;
        //     for(int j = 0; j < n; j++){
        //         for(int k = 0; k < n; k++){
        //             if(nums[i] + cnt == nums[k]){ 
        //                 cnt++;
        //                 break;
        //             }
        //         }
        //     }
        //     ans = max(ans, cnt);
        // }
        // return ans;

        // int n = nums.size();
        // set<int> st;
        // for(int i : nums){
        //     st.insert(i);
        // }
        // vector<int> num;
        // for(auto i : st){
        //     num.push_back(i);
        // }

        // int ans = 0;
        // if(n == 0) return 0;
        // int cnt = 1;
        // for(int i = 1; i < num.size(); i++){
        //     if(num[i] == num[i-1]+1) cnt++;
        //     else{
        //         ans = max(ans, cnt);
        //         cnt = 1;
        //     }
        //     cout << cnt << " "; 
        // }
        // ans = max(ans, cnt);
        // return ans;


        // unordered_map<int, int> mp;
        // int n = nums.size();
        // int ans = 0;

        // for(int i : nums){
        //     mp[i]++;
        // }
        // for(int i = 0; i < n; i++){
        //     if(mp.find(nums[i] - 1) == mp.end()){
        //         int len = 1;
        //         int num = nums[i]+1;
        //         while(mp.find(num) != mp.end()){
        //             len++;
        //             num++;
        //         }
        //         ans = max(ans, len);
        //     }
        // }
        // return ans;

        sort(nums.begin(), nums.end());
        if(nums.size() == 0) return 0;
        int ans = 1;
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++){
            while(i < nums.size() && nums[i] == nums[i-1]) i++;

            if(i < nums.size() && nums[i] == nums[i-1]+1){
                cnt++;
            }
            else{
                cnt = 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};