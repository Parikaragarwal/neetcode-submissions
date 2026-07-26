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
    void dfs(TreeNode* root,int &count,TreeNode*& ans,int k){
        if(!root){
            return;
        }
        if(ans){
            return;
        }

        dfs(root->left,count,ans,k);
        count++;
        if(count==k){
            ans=root;
        }
        dfs(root->right,count,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode* ans = NULL;
        dfs(root,count,ans,k);
        return ans?ans->val:0; 
    }
};
