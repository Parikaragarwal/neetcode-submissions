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
    bool checkOneExists(TreeNode* root,TreeNode* p){
        if(!root){
            return false;
        }
        if(root==p){
            return true;
        }
        return checkOneExists(root->left,p) || checkOneExists(root->right,p);
    }
    bool checkExists(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*& ans){
        if(!root){
            return false;
        }
        if(ans){
            return true;
        }
        if(
            !(checkExists(root->left,p,q,ans)
            ||
            checkExists(root->right,p,q,ans))
            &&
            checkOneExists(root,p)
            && 
            checkOneExists(root,q)
            ){
                ans=root;
                return true;
            }else{
                return false;
            }
            
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        checkExists(root,p,q,ans);
        return ans;
    }
};
