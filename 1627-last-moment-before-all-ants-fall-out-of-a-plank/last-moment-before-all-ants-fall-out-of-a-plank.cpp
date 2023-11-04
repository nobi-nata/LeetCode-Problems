class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // sort(left.begin(), left.end());
        // sort(right.begin(), right.end());
        int lm = 0;
        int rm = n;
        for(int i : right) rm = min(rm, i);
        for(int i : left) lm = max(lm, i);
        // if(left.size() == 0){
        //     return n - rm;
        // }
        // if(right.size() == 0){
        //     return lm;
        // }

        return max(lm, n - rm);

    }
};