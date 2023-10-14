class Solution {
public:
    void recur(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> v, int i, int sum){
        if(i == candidates.size() || sum > target) return;
        if(sum == target){
            ans.push_back(v);
            return;
        }

        recur(candidates, target, ans, v, i+1, sum);
        v.push_back(candidates[i]);
        recur(candidates, target, ans, v, i, sum+candidates[i]);
        

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        recur(candidates, target, ans, {}, 0, 0);
        return ans;
    }
};