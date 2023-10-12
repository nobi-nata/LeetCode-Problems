/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            ans.push_back(-201);
            return;
        }
        ans.push_back(root->val);
        inorder(root->left, ans);
        
        inorder(root->right, ans);

    }

    void solve(TreeNode* root, vector<pair<TreeNode*, vector<int>>> &vec){
        if(root == NULL) return;
        vector<int> ans;
        inorder(root, ans);
        vec.push_back({root, ans});

        solve(root->left, vec);
        solve(root->right, vec);

    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<pair<TreeNode*, vector<int>>> v;
        vector<TreeNode*> ans;
        set<vector<int>> visited;
        solve(root, v);

        for(int i = 0; i < v.size()-1; i++){
            for(int j = i+1; j < v.size(); j++){
                if(v[i].second == v[j].second && visited.find(v[i].second) == visited.end()){
                    ans.push_back(v[i].first);
                    visited.insert(v[i].second);
                    break;
                }
            }
        }

        
        return ans;
    }
};