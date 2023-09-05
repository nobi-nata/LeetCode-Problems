class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        queue<int> qp;
        queue<int> qn;
        for(auto i : nums){
            if(i < 0){
                qn.push(i);
            }
            else{
                qp.push(i);
            }
        }
        for(int i = 0; i < nums.size(); i++){
            ans.push_back(qp.front());
            qp.pop();
            i++;
            ans.push_back(qn.front());
            qn.pop();
        }
        return ans;
    }
};