class Solution {
public:
    bool rotateString(string s, string goal) {
        int ss = s.size();
        int gs = goal.size();
        if(gs != ss) return false;
        int i = 0;
        while(i < ss){
            if(s == goal) return true;
            char ch = s.back();
            s.pop_back();
            s = ch + s;
            i++;
        }
        
        return false;
    }
};