class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int,int> vis;

        for(auto i : adjacentPairs){
            vis[i[0]] = 0;
            vis[i[1]] = 0;
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        int first = 1e6;
        int last = 1e6;

        for(auto i : mp){
            if(i.second.size() == 1 && first == 1e6){
                first = i.first;
                // mp.erase(i.first);
            }
            else if(i.second.size() == 1){
                last = i.first;
                // mp.erase(i.first);
            }
        }
        vector<int> ans;
        ans.push_back(first);
        vis[first] = 1;
        int var = first;
        while(ans.size() < adjacentPairs.size()){
            
            int ele = mp[var][0];
            if(vis[ele] || ele == last){
                ele = mp[var][1];
            }
            
            vis[ele] = 1;
            ans.push_back(ele);
            var = ele;

        }
        ans.push_back(last);
        return ans;

    }
};