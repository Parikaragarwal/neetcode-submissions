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
private:
    int dfs(TreeNode* root,int mx){
        if(!root){
            return 0;
        }
        mx=max(mx,root->val);
        if(mx>root->val){
            return dfs(root->left,mx)+dfs(root->right,mx);
        }else{
            return dfs(root->left,mx)+dfs(root->right,mx)+1;
        }
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};
