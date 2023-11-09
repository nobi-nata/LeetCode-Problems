class Solution {
public:
    // int fact(int n){
    //     if(n == 1) return 1;
    //     return n + fact(n-1);
    // }
    int countHomogenous(string s) {
        long long ans = 0;
        int mod = 1e9+7;
        long long n = s.size();

        long long i = 1; 
        long long j = 0;

        if(n == 1) return 1;
        while(i < n){
            if(s[i] != s[i-1]){
                ans = (ans + ((i-j)*(i-j+1)/2)%mod)%mod;
                j = i;
            }
            i++;
        }
        ans = (ans + ((i-j)*(i-j+1)/2)%mod)%mod;
        return (int)ans;
    }
};