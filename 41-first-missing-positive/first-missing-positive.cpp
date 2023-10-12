class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //TC: O(n^2)
        // int n = nums.size();
        // int num = 1;
        // for(int i = 0; i < n; i++){
        //     int j;
        //     for(j = 0; j < n; j++){
        //         if(num == nums[j]) break;
        //     }
        //     if(j == n) break;
        //     num++;
        // }
        // return num;

        //TC: O(nlogn)

        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // auto it = unique(nums.begin(), nums.end());

        // nums.resize(distance(nums.begin(), it));
        // int j = 0;
        // int i = 1;
        // while(j < n){
        //     while(j < n && nums[j] < 1){
        //         j++;
        //     }
        //     if(j == n) break;
        //     if(nums[j] == i){
        //         cout << 'y';
        //         i++;
        //     }
        //     else return i;
        //     j++;
        // }
        // return i;
        
        //TC: O(n)

        // int n = nums.size();
        // int i = 0;
        // while(i < n){
        //     if(nums[i] == (i+1) || nums[i] <= 0 || nums[i] > n){
        //         i++;
        //         continue;
        //     }
            
        //     int idx1 = i;
        //     int idx2 = nums[i] - 1;
        //     if(nums[idx1] == nums[idx2]){
        //         i++;
        //         continue;
        //     }
        //     swap(nums[idx1],nums[idx2]);
        // }
        // for(int i = 0; i < n; i++){
        //     if(nums[i] != i+1){
        //         return i+1;
        //     }
        // }
        // return n+1;

        //TC: O(n)

        int n = nums.size();
        int contains = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1) contains++;
            if(nums[i] <= 0 || nums[i] > n){ 
                nums[i] = 1;
            }
        }
        if(contains == 0) return 1;

        for(int i = 0; i < n; i++){
            int a = abs(nums[i]);
            if(a == n){
                nums[0] = -abs(nums[0]);
            }
            else nums[a] = -abs(nums[a]);
        }

        for(int i = 1; i < n; i++){
            if(nums[i] > 0)
                return i;
        }
        if(nums[0] > 0) return n;
        return n+1;
    }
};