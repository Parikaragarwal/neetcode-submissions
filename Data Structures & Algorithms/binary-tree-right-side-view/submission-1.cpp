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
    void dfs(TreeNode* root,int depth,vector<int> &ans){
        if(!root){
            return;
        }
        if(ans.size()==depth){
            ans.push_back(root->val);
        }
        dfs(root->right,depth+1,ans);
        dfs(root->left,depth+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        int depth=0;

        dfs(root,depth,ans);
        return ans;


        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                if(i==sz-1){
                    ans.push_back(node->val);
                }
            }
        }
        return ans;
    }
};
