class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& s) {
        map<int, vector<int>> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]].push_back(i);
            
        }
        vector<vector<int>> ans;
        for(auto i : mp){
            int k = 0;
            vector<int> temp;
            for(auto j : i.second){
                
                
                temp.push_back(j);
                cout << j << ' ';
                k++;
                if(k == i.first){
                    ans.push_back(temp);
                    temp.clear();
                    k = 0;
                }
            }
        }
        return ans;
    }
};