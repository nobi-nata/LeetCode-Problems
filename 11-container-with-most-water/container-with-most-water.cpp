class Solution {
public:
    int maxArea(vector<int>& height) {
        //TC: O(n^2)
        // int ans = 0;
        // int n = height.size();
        // for(int i = 0; i < n; i++){
        //     int leftmax = INT_MIN;
        //     int ind = 0;
        //     for(int j = i+1; j < n; j++){
        //         ans = max(ans, (j-i)*min(height[i], height[j]));
        //     }            
        // }
        // return ans;


        //TC: O(n)

        int n = height.size();
        int i = 0;
        int j = n-1;
        int ans = 0;

        while(i < j){
            int h = min(height[i], height[j]);
            int w = j-i;

            ans = max(ans, h*w);

            if(height[i] <= height[j]) i++;
            else j--;
        }

        return ans;
    }
};