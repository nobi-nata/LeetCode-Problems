class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // int n = nums.size();

        // if(n < 3) return false;

        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         for(int k = j+1; k < n; k++){
        //             if(nums[i] < nums[k] && nums[k] < nums[j]) return true;
        //         }
        //     }
        // }
        // return false;



         stack<int> s;
        int third = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < third) return true;
            while (!s.empty() && s.top() < nums[i]) {
                third = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};