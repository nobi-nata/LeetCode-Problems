class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int j = 0;
        int i = 0;
        long sum = 0;
        long size = 0;
        long ans = 0;
        while(i < n){
            size = i-j+1;
            sum += nums[i];

            while((nums[i]*size - sum) > k){
                size--;
                sum -= nums[j];
                j++;
            }
            ans = max(ans, size);
            i++;
        }
        return ans;
    }
};