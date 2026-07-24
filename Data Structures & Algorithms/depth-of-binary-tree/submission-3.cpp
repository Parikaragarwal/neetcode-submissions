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

        // queue<TreeNode*> q;
        // int level = 0;
        // int nodes = 1;
        // q.push(root);

        // while(!q.empty()){
        //     int children=0;
        //     while(nodes--){
        //         TreeNode* r = q.front();
        //         q.pop();
        //         if(r->left){
        //             q.push(r->left);
        //             children++;
        //         }
        //         if(r->right){
        //             q.push(r->right);
        //             children++;
        //         }
        //     }
        //     level++;
        //     nodes=children;
        // }
        // return level;

        stack<pair<TreeNode*,int>> s;
        int ans = 1;
        s.push({root,1});
        while(!s.empty()){
            TreeNode* node = s.top().first;
            int depth = s.top().second;
            s.pop();
            if(node->left){
                s.push({node->left,depth+1});
                ans= max(ans,depth+1);
            }
            if(node->right){
                s.push({node->right,depth+1});
                ans= max(ans,depth+1);
            }
        }
        return ans;
    }
};
