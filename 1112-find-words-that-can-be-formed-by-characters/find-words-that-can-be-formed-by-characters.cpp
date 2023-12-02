class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        int ans = 0;

        for(char i : chars) mp[i]++;
        for(auto str : words){
            unordered_map<char, int> mp1;
            for(char it : str) mp1[it]++;
            int i;
            for(i = 0; i < str.size(); i++){
                if(mp[str[i]] < mp1[str[i]]) break;
            }
            if(i == str.size()) ans += str.size();
        }
        return ans;
    }
};