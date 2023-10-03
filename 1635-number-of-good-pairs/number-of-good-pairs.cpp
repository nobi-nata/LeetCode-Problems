class Solution {
public:
    int fact(int num){
        if(num == 1) return 1;
        return num+fact(num-1);
    }

    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i : nums){
            mp[i]++;
        }
        int ans = 0;
        for(auto i : mp){
            if(i.second > 1){
                cout << i.second;
                ans += fact(i.second-1);
            }
        }
        return ans;
    }
};