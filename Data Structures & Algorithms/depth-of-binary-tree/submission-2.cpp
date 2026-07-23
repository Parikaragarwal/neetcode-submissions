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
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        // return max(maxDepth(root->left),maxDepth(root->right))+1;

        queue<TreeNode*> q;
        int level = 0;
        int nodes = 1;
        q.push(root);

        while(!q.empty()){
            int children=0;
            while(nodes--){
                TreeNode* r = q.front();
                q.pop();
                if(r->left){
                    q.push(r->left);
                    children++;
                }
                if(r->right){
                    q.push(r->right);
                    children++;
                }
            }
            level++;
            nodes=children;
        }
        return level;
    }
};
