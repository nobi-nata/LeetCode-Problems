class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> vec;

        for(int i = 0; i < nums.size(); i++){
            int cnt = 1;
            while(i < nums.size()-1 && nums[i] == nums[i+1]){ 
                cnt++;
                i++;
            }
            vec.push_back({nums[i], cnt});
        }

        int i = vec.size()-1;

        int ans = 0;

        while(i >= 0){           

            ans += vec[i].second*i;
            i--;
        }
        return ans;
    }
};