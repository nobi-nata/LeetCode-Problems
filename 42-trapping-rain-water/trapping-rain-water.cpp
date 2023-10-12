class Solution {
public:
    int trap(vector<int>& height) {
        //TC: O(n^2)

        // int n = height.size();
        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     int left = 0;
        //     int right = 0;
        //     for(int j = i-1; j >= 0; j--){
        //         left = max(left, height[j]);
        //     }
        //     for(int j = i+1; j < n; j++){
        //         right = max(right, height[j]);
        //     }
        //     int h = min(left, right);
        //     int w = h - height[i];
        //     if(w > 0) ans += w;  // if if(w>0) is to be removed change in for condition j = i instead of i-1 & i+1;
        // }
        // return ans;

        //TC: O(n) SC: O(n)

        // int n = height.size();
        // vector<int> prefix(n, 0);
        // vector<int> suffix(n , 0);
        // prefix[0] = height[0];
        // suffix[n-1] = height[n-1];

        // for(int i = 1; i < n; i++){
        //     prefix[i] = max(prefix[i-1], height[i]);
        //     suffix[n-i-1] = max(suffix[n-i], height[n-i-1]);
        // }
        // int ans = 0;
        // for(int i= 0; i < n; i++){
        //     ans += min(prefix[i], suffix[i]) - height[i];
        // }
        // return ans;

        //TC: O(n)

        int n = height.size();
        int i = 0;
        int j = n -1;
            
        int prefix = 0;
        int suffix = 0;
        int ans = 0;

        while(i < j){
            prefix = max(prefix, height[i]);
            suffix = max(suffix, height[j]);

            if(prefix <= suffix){
                ans += prefix - height[i];
                i++;
            }
            else{
                ans += suffix - height[j];
                j--;
            }
        }

        return ans;
    }
};