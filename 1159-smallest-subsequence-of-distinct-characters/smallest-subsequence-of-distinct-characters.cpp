class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> mp;
        for(auto i : s) mp[i]++;
        vector<int> vis(26, 0);
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            mp[s[i]]--;
            if(vis[s[i] - 'a']) continue;

            while(!ans.empty() && ans.back() > s[i] && mp[ans.back()]){
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i] - 'a'] = 1;
        }
        return ans;
    }
};