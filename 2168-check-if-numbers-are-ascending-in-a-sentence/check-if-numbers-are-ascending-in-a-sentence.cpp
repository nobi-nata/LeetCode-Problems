class Solution {
public:
    bool areNumbersAscending(string s) {
        int num = 0;
        int prev = -1;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                while(i < n && s[i] != ' '){
                    num = num*10 + s[i];
                    i++;
                }
                if(num > prev){
                    prev = num;
                    num = 0;
                }
                else return false;
            }
            else{
                while(i < n && s[i] != ' ') i++;
            }
        }
        return true;
    }
};