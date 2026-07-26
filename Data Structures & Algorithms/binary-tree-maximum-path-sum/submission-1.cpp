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
    int maxPath(TreeNode* root,int& mx){
        if(!root){
            return 0;
        }
        int leftsum = max(0,maxPath(root->left,mx));
        int rightsum = max(0,maxPath(root->right,mx));

        int totalsum = root->val+leftsum+rightsum;
        if(totalsum>mx){
            mx=totalsum;
        }
        return max(leftsum,rightsum)+root->val;
    }
    int maxPathSum(TreeNode* root) { 
        int mx=INT_MIN;
        maxPath(root,mx);
        return mx;
    }
};
