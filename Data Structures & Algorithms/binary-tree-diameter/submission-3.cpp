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

    int dfs(TreeNode* root,int &res){
        if(!root){
            return 0;
        }
        int l = dfs(root->left,res);
        int r = dfs(root->right,res);
        res = max(res,l+r);
        return max(l,r)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }

        // int diameter = height(root->left)+height(root->right);
        // return max(diameter,max(
        //     diameterOfBinaryTree(root->left),
        //     diameterOfBinaryTree(root->right)
        //     )
        //     );
        int res=0;
        dfs(root,res);
        return res;
    }
};
