class Solution {
public:
    bool checkbit(int num, int i){
        if(num & (1 << i)) return true;
        return false;
    }
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int count =0;
            for(int j = 0; j < n; j++){
                if(checkbit(nums[j], i) == true){
                    count++;
                }
            }
            if(count%3 != 0){
                ans = ans + (1 << i);
            }
        }
        return ans;
    }
};