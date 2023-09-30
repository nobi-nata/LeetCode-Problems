// class Solution {
// public:
//     void search(vector<vector<int>> adj, vector<int> &ans, int n, int k, int c, unordered_set<int> &st){
//         ans[k] = c;
//         for(auto i : adj[k]){
//             st.insert(i);
//         }
//         for(int i = k+1; i < n; i++){
//             if(st.find(i) == st.end() && ans[i] == 0){
//                 search(adj, ans, n, i, c, st);
//             }
//         }
//     }

//     vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
//         vector<vector<int>> adj(n);
//         for(int i = 0; i < paths.size(); i++){
//             adj[paths[i][0] - 1].push_back(paths[i][1] - 1);
//             adj[paths[i][1] - 1].push_back(paths[i][0] - 1);
//         }
//         // vector<int> vis(n, 0);
//         int c = 1;
//         vector<int> ans(n, 0);
//         for(int i = 0; i < n; i++){
//             unordered_set<int> st;
//             if(ans[i] == 0){
//                 search(adj, ans, n, i, c, st);
//             }
//             c++;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    bool ispossible(int nbr,int col,vector<int> adj[],vector<int> &color)
    {
        for(auto x:adj[nbr])
        {
            if(color[x]==col)return false;
        }
        return true;
    }
    void dfs(int i,vector<int> &color,vector<int> adj[])
    {
        for(auto x:adj[i])
        {
            if(color[x] == -1)
          {  
              for(int col=1;col<=4;col++)
            {
                if(ispossible(x,col,adj,color))
                {
                    color[x]=col;
                }
            }
             dfs(x,color,adj);
          }

        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        for(auto x:paths)
        {
            adj[x[0]-1].push_back(x[1]-1);
            adj[x[1]-1].push_back(x[0]-1);
        }
        vector<int> color(n,-1);
        // vector<int> vis(n+1,0);
       
        
             for(int i=0;i<n;i++)
            { 
                if(color[i] == -1) 
                {
                    color[i]=1;
                    dfs(i,color,adj);
                }
            }
            
        return color;
    }
};