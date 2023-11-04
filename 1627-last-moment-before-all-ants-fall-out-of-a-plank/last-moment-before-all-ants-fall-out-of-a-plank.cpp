class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        if(left.size() == 0){
            // if(right[0] == 0 && right.size() == 1) return 0;
            return n - right[0];
        }
        if(right.size() == 0){
            // if(left[left.size()-1] == n && left.size() == 1) return 0;
            return left[left.size()-1];
        }

        int ans = max(left[left.size()-1], n - right[0]);

        return ans;
    }
};