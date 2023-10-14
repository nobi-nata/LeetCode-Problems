class Solution {
public:
    int partitionString(string s) {
        // unordered_map<char, int> mp;
        // int cnt = 1;
        // for(int i = 0; i  <s.size(); i++){
        //     if(mp.find(s[i]) != mp.end()){
        //         cnt++;
        //         mp.clear();
        //     }
        //     mp[s[i]]++;
        // }
        // return cnt;

        int feq[26] = {0};
        int l = 0, r = 0, n = s.length();
        int cnt = 1;
        for(; r < n; r++){
            int ch = s[r] - 'a';
            feq[ch]++;
            if(feq[ch] > 1){
                cnt++;
                while(l < r){
                    feq[s[l++] - 'a']--;
                }
            }
        }
        return cnt;
    }
};