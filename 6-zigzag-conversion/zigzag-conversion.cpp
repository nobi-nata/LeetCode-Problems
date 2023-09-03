class Solution {
public:
    string convert(string s, int numRows) {
        // int i = 0;
        // int n = s.size();
        // vector<string> v(numRows);
        // while(i < n){
        //     for(int j = 0; j < numRows && i < n; j++){
        //         v[j].push_back(s[i]);
        //         i++;
        //     }
        //     for(int j = numRows-2 ; j > 0 && i < n; j--){
        //         v[j].push_back(s[i]);
        //         i++;
        //     }
        // }
        // string ans = "";
        // int k = 0;
        // while(k < numRows){
        //     ans += v[k];
        //     k++;
        // }
        // return ans;


        if(numRows <= 1) return s;
        vector<string>v(numRows, ""); 
        int j = 0, dir = -1;

        for(int i = 0; i < s.length(); i++)
        {
            if(j == numRows - 1 || j == 0) dir *= (-1); 
            v[j] += s[i];
            if(dir == 1) j++;
            else j--;
        }

        string res;
        for(auto it : v) res += it; 
        return res;
    }
};