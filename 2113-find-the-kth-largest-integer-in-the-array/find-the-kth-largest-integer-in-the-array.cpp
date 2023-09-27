class Solution {
public:
    static bool cmp(string a, string b){
        if(a.size() == b.size()){
            if(a < b) return true;
            return false;
        }
        else if(a.size() < b.size()) return true;
        return false;
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        int n = nums.size();

        return nums[n-k];
    }
};