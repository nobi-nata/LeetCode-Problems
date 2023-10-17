class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, int> parent;
        // unordered_map<int, int> child;
        vector<int> adj[n];

        for(int i = 0; i < n; i++){
            parent[i] = 0;

        }

        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){ 
                parent[leftChild[i]]++;
                adj[i].push_back(leftChild[i]);
            }
            if(rightChild[i] != -1){ 
                parent[rightChild[i]]++;
                adj[i].push_back(rightChild[i]);
            }
        }

        int node = 0;
        int cntz = 0;
        for(auto i : parent){
            if(i.second > 1) return false;
            if(i.second == 0){ 
                node = i.first;
                cntz++;
            }
        }
        if(cntz == 0) return false;
        if(cntz > 1) return false;

        queue<int> q;
        vector<int> vis(n, 0);
        q.push(node);
        while(!q.empty()){
            int ele = q.front();
            vis[ele] = 1;
            q.pop();
            for(auto i : adj[ele]){
                q.push(i);
            }
        }
        for(int i = 0; i < n; i++){
            if(vis[i] == 0) return false;
        }
        return true;
    }
};