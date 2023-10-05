class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int freq = 1;
        int ele1 = nums[0];
        int freq1 = 0;

        for(int i = 1; i < nums.size(); i++){
            if(freq1 == 0 && ele != nums[i]){
                ele1 = nums[i];
                freq1 = 1;
            }
            else if(freq == 0 && ele1 != nums[i]){
                ele = nums[i];
                freq = 1;
            }
            else if(ele == nums[i]){
                freq++;
            }
            else if(ele1 == nums[i]){
                freq1++;
            }
            else{
                freq--;
                freq1--;
            }
            
        }
        int cnt = 0, cnt1 = 0;
        for(auto i : nums){
            if(i == ele) cnt++;
            if(i == ele1) cnt1++;
        }
        if(cnt > nums.size()/3 && freq && freq1 && cnt1 > nums.size()/3){
            return {ele, ele1};
        }
        if(cnt > nums.size()/3 && freq){
            return {ele};
        }
        if(cnt1 > nums.size()/3 && freq1){
            return {ele1};
        }
        return {};
    }
};