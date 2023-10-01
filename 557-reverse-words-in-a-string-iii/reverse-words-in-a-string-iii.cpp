class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;

        while(j < n){
            while(j < n && s[j] != ' ') j++;
            int next = j;
            j--;
            while(j < n && i < n && i < j){
                swap(s[i++], s[j--]);
            }
            j = next+1;
            i = next+1;
        }
        return s;
    }
};