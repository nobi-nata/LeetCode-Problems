class Solution {
public:
    vector<vector<int>> ans;

    void per(vector<int> arr, int target, int ind, vector<int> v){
        if(target == 0){
            ans.push_back(v);
            return;
        }

        for(int i = ind; i < arr.size(); i++){
            if(arr[i] > target) return;

            if(i > ind && arr[i] == arr[i-1]) continue;

            v.push_back(arr[i]);
            per(arr, target - arr[i], i+1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        per(candidates, target, 0, {});
        return ans;
    }
};