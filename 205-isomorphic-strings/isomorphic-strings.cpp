class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, char> m;
        int i = 0;
        int e = s.size()-1;
        while(i <= e){
            if((mp.find(s[i]) != mp.end() && mp[s[i]] != t[i]) || (m.find(t[i]) != m.end() && m[t[i]] != s[i])) return false;
            mp[s[i]] = t[i];
            m[t[i]] = s[i];
            i++;
        }
        return true;
    }
};