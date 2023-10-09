class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //TC: O(n^3)
        
        // int n = nums.size();
        // int ans = INT_MIN;
        // for(int i = 0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         int prod = 1;
        //         for(int k = i; k <= j; k++){
        //             prod *= nums[k];
        //         }
        //         ans = max(ans, prod);
        //     }
        // }
        // return ans;

        //TC: O(n^2);

        // int n = nums.size();
        // int ans = INT_MIN;
        // for(int i = 0; i < n; i++){
        //     int prod = 1;
        //     for(int j = i; j < n; j++){
        //         prod *= nums[j];
        //         ans = max(ans, prod);
        //     }
        // }
        // return ans;
        
        //TC: O(n);
        
        // int maxi = INT_MIN;
        // int pf = 1;
        // int sf = 1;
        // for(int i = 0; i < nums.size(); i++){
        //     if(pf == 0) pf = 1;
        //     pf = pf * nums[i];
        //     maxi = max(maxi, pf);
        // }
        // for(int i = nums.size()-1; i >= 0; i--){
        //     if(sf == 0) sf = 1;
        //     sf = sf * nums[i];
        //     maxi = max(maxi, sf);
        // }
        // return maxi;

        //TC: O(n);

        int n = nums.size();
        int ans = nums[0];
        int minProd = nums[0];
        int maxProd = nums[0];

        for(int i = 1; i < n; i++){
            int curr = nums[i];
            int x = minProd*curr;
            int y = maxProd*curr;
            minProd = min(curr, min(x, y));
            maxProd = max(curr, max(x, y));
            ans = max(ans, max(minProd, maxProd));
        }
        return ans;
    }
};