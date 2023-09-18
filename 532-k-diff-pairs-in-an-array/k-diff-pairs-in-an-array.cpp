class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // unordered_map<int, int> mp;
        // vector<int> vec;
        // for(auto i : nums){
        //     mp[i]++;
        // }
        // int c = 0;
        // for(auto i : mp){
        //     vec.push_back(i.first);
        //     if(i.second > 1) c++;
        // }
        // sort(vec.begin(), vec.end());
        // int n = vec.size();
        // if(k == 0){
        //     return c;
        // }
        // if(n == 1) return 0;
        // int ans = 0;

        // int i = 0;
        // int j = 1;

        // while(j < n){
        //     if(i!=j && (vec[j] - vec[i]) == k){
        //         ans++;
        //         j++;
        //     }
        //     else if(i!=j && (vec[j] - vec[i]) > k){
        //         i++;
        //     }
        //     else{
        //         j++;
        //     }
        // }
        // return ans;


        // unordered_map<int, int> mp;
        // for(auto i : nums){
        //     mp[i]++;
        // }
        // int cnt = 0;
        // for(auto i : mp){
        //     if(k == 0){
        //         if(i.second > 1){
        //             cnt++;
        //         }
        //     }
        //     else if(mp.find(i.first+k) != mp.end()){
        //         cnt++;
        //     }
        // }
        // return cnt;


        sort(nums.begin(),nums.end());
        int ans=0,i=0,j=1;
        for(i,j;i<nums.size() and j<nums.size();)
        {
            if(i==j or nums[j]-nums[i]<k)
                j++;
            else 
            {
                if(nums[j]-nums[i]==k)
                {
                    ans++;
                    j++;
                    for(;j<nums.size();j++)
                        if(nums[j]!=nums[j-1])
                            break;
                    if(j==nums.size())
                    return ans;
                    // j--;                  
                }
                i++;
                while(i<j and nums[i]==nums[i-1])
                    i++;
            }
        }
        return ans;
    }
};