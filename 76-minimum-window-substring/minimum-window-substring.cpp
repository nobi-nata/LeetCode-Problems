class Solution {
public:
    bool check(vector<int> scnt, vector<int> tcnt){
        for(int i = 0; i < 256; i++){
            if(scnt[i] < tcnt[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> scnt(256, 0);
        vector<int> tcnt(256, 0);

        if(t.size() > s.size()) return "";

        for(int i = 0; i < t.size(); i++) tcnt[t[i]]++;

        int st = 0;
        int e = 0;
        string ans = "";

        while(st <= e && e < s.size()){
            scnt[s[e]]++;

            while(st <= e && scnt[s[st]] >= tcnt[s[st]]){
                string temp = s.substr(st, e-st+1);
                // cout << scnt[s[st]] << tcnt[s[st]] ;
                // cout << st << temp <<' ';
                if(check(scnt, tcnt) && (ans.size() > temp.size() || ans == "")){
                    ans = temp;
                }
                if(scnt[s[st]] == tcnt[s[st]]) break;
                scnt[s[st]]--;
                st++;
            }
            e++;
        }
        return ans;
    }
};