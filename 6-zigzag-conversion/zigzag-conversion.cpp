class Solution {
public:
    string convert(string s, int numRows) {
        int i = 0;
        int n = s.size();
        vector<string> v(numRows);
        while(i < n){
            for(int j = 0; j < numRows && i < n; j++){
                v[j].push_back(s[i]);
                i++;
            }
            for(int j = numRows-2 ; j > 0 && i < n; j--){
                v[j].push_back(s[i]);
                i++;
            }
        }
        string ans = "";
        int k = 0;
        while(k < numRows){
            ans += v[k];
            k++;
        }
        return ans;
    }
};