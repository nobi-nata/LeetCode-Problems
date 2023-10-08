class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Like insertion sort -> go to last k elements and bring them to start
        // int n = nums.size();
        // k = k%n;
        
        // for(int i = n - k; i < n; i++){
        //     int j = i;
        //     while(j > (i - n + k)){
        //         swap(nums[j], nums[j-1]);
        //         j--;
        //     }
        // }
        
        // using deque;
        list<int> dq;

        for(int i : nums) dq.push_back(i);

        while(k){
            int ele = dq.back();
            dq.pop_back();
            dq.push_front(ele);
            k--;
        }
        int j = 0;
        for(auto i : dq){
            nums[j++] = i;
        }


    }
};