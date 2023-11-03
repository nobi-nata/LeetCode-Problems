class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i = 0;
        vector<string> ans;
        int ele = target[target.size()-1];
        for(int num = 1; num <= n; num++){
            ans.push_back("Push");
            if(i < target.size() && target[i] != num){
                ans.push_back("Pop");
            }
            else{
                i++;
            }
            if(ele == num) break;
            
        }
        return ans;
    }
};