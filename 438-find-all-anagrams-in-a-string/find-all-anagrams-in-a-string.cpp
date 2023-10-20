class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pcnt(26, 0);
        vector<int> scnt(26, 0);
        int pl = p.size();
        vector<int> ans;

        for(int i = 0; i < pl; i++){
            pcnt[p[i]-'a']++;
        }

        for(int i = 0 ; i < s.size(); i++){
            scnt[s[i]-'a']++;
            if(i > pl-1){
                scnt[s[i-pl]-'a']--;
            }

            bool anagram = true;
            for(int j = 0; j < 26; j++){
                if(pcnt[j] != scnt[j]){
                    anagram = false;
                    break;
                }
            }
            if(anagram) ans.push_back(i-pl+1);
        }
        return ans;
    }
};