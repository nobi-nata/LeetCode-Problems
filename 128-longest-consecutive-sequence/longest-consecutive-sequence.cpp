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

        int n = nums.size();
        set<int> st;
        for(int i : nums){
            st.insert(i);
        }
        vector<int> num;
        for(auto i : st){
            num.push_back(i);
        }

        int ans = 0;
        if(n == 0) return 0;
        int cnt = 1;
        for(int i = 1; i < num.size(); i++){
            if(num[i] == num[i-1]+1) cnt++;
            else{
                ans = max(ans, cnt);
                cnt = 1;
            }
            cout << cnt << " "; 
        }
        ans = max(ans, cnt);
        return ans;
    }
};