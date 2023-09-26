class Solution {
public:
    bool dfs(vector<vector<int>> adj, vector<int> &vis, int node,vector<int> &pvis){
        vis[node] = 1;
        pvis[node] = 1;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(!dfs(adj, vis, i, pvis)) return false;
            }
            else if(pvis[i]){
                return false;
            }
        }
        pvis[node] = 0;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pvis(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                // vector<int> pvis(numCourses, 0);
                if(!dfs(adj, vis, i, pvis)) return false;
            }
        }
        return true;

    }
};