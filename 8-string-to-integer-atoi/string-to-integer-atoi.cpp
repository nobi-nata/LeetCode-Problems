class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        while(i < n && s[i] == ' ' && s[i] != '-'){
            i++;
        }
        bool flag = false;
        if(s[i] == '-'){
            flag = true;
            i++;
        }
        else if(s[i] == '+') i++;

        if(s[i] >= '0' && s[i] <= '9'){
            int ans = 0;
            while(i < n && s[i] >= '0' && s[i] <= '9'){
                int num = s[i] - '0';
                if(ans > (INT_MAX - num)/10){
                    if(flag){
                        return INT_MIN;
                    }
                    return INT_MAX;
                }
                else ans = 10*ans + num;
                i++;
            }
            if(flag) ans *= -1;
            return ans;
        }
        return 0;
    }
};