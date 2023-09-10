class Solution {
public:
    int kthFactor(int n, int p) {
        vector<int> s;
        vector<int> e;

        for(int i = 1; i*i <= n; i++){
            if(n%i == 0){
                if(n/i == i){
                    s.push_back(i);
                }
                else{
                    e.push_back(n/i);
                    s.push_back(i);
                }
                if(p-1 < s.size()) return s.back();
            }
        }
        if(p > s.size()+e.size()) return -1;
        p = p-s.size();
        int k = e.size() - p;
        return e[k];
    }
};