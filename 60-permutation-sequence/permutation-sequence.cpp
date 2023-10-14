class Solution {
public:
    void per(string str, int n, int k, string &ans, int ind, int &cnt){
        if(ans != "") return;
        if(ind == n){
            cnt++;
            if(k == cnt) ans = str;
            return;
        }

        for(int i = ind; i < n; i++){
            swap(str[i], str[ind]);
            sort(str.begin()+ind+1, str.end());
            per(str, n, k, ans, ind+1,cnt);
            swap(str[i], str[ind]);
        }
    }
    string getPermutation(int n, int k) {
        string str = "";
        int i = 1;
        while(i <= n){
            str += char(i + '0');
            i++;
        }
        // cout << str;
        string ans = "";
        int cnt = 0;
        per(str, n, k, ans, 0, cnt);
        return ans;
    }
};