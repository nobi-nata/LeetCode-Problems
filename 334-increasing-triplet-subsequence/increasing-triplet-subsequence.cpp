class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // if(nums.size() < 3) return false;
        // for(int i = 0; i < nums.size() - 2; i++){
        //     for(int j = i+1; j < nums.size() - 1; j++){
        //         for(int k = j+1; k < nums.size(); k++){
        //             if(nums[i] < nums[j] && nums[j] < nums[k]) return true;
        //         }
        //     }
        // }
        // return false;

        // if(nums.size()<3)return false;
        // int left = INT_MAX;
        // int mid = INT_MAX;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i] > mid) return true;
        //     else if (nums[i] > left && nums[i] < mid)
        //     {
        //         mid = nums[i];
        //     }
        //     else if(nums[i] < left )
        //     {
        //         left = nums[i];
        //     }
        // }
        // return false;

        // int n = nums.size();
        // vector<int > res;
        // for(int i = 0 ; i < n ; i++) {
        //     if(res.empty() || res.back() < nums[i])
        //         res.push_back(nums[i]);
        //     else {
        //         auto it = lower_bound(res.begin(), res.end(), nums[i]);
        //         *it = nums[i];
        //     }
        //     if(res.size() == 3)
        //         return true;
        // }
        // return false;

        // int a=INT_MIN,b=INT_MIN;
        // for(auto i:nums)
        // {
        //     if(a==INT_MIN or i <= a)
        //         a=i;
        //     else if(b==INT_MIN or i <= b)
        //         b=i;
        //     else
        //         return true;
        // }
        // return false;

        

        int n = nums.size();
        
        // left_min[i] will store the minimum from left till ith

        vector<int> left_min(n);
        
        // right_max[i] will store the maximum from right till ith

        vector<int> right_max(n);
        
        // fill left_min array

        left_min[0] = nums[0];

        for(int i = 1; i < n; i++)
        {
            left_min[i] = min(left_min[i - 1], nums[i]);
        }
        
        // fill right_max array

        right_max[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--)
        {
            right_max[i] = max(right_max[i + 1], nums[i]);
        }
        
        // check that is there any element which has smaller element on left side and greater element on right side

        for(int i = 1; i < n - 1; i++)
        {
            if(left_min[i - 1] < nums[i] && nums[i] < right_max[i + 1])
            {
                return true;
            }
        }
        
        return false;

    }
};