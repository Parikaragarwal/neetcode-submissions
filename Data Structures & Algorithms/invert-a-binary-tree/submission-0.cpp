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
    TreeNode* invertTree(TreeNode* root) {
        // if(!root){
        //     return root;
        // }

        // TreeNode* l= root->left;
        // TreeNode* r= root->right;

        // root->left = invertTree(r);
        // root->right = invertTree(l);
        // return root;

        if(!root){
            return NULL;
        }

        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* root = s.top();
            s.pop();
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            root->left = r;
            root->right = l;
            if(r){
                s.push(r);
            }
            if(l){
                s.push(l);
            }
        }
        return root;
    }
};
