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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }

    int dfs(TreeNode* root,bool &ans){
        if(!root){
            return 0;
        }

        int lh = dfs(root->left,ans);
        int rh = dfs(root->right,ans);

        ans = ans && abs(lh-rh)<=1;

        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }

        // bool ans = abs(height(root->left)-height(root->right))<=1;

        bool ans = true;
        dfs(root,ans);
        return ans;
    }
};
