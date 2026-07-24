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
        // return ans && isBalanced(root->left) && isBalanced(root->right);

        // bool ans = true;
        // dfs(root,ans);
        // return ans;


        unordered_map<TreeNode*,int> mp;
        stack<TreeNode*> s;
        mp[NULL]=0;

        s.push(root);
        bool ans = true;
        while(!s.empty()){
            TreeNode* node = s.top();
            if(node->left && !mp.contains(node->left)){
                s.push(node->left);
            }else if(node->right && !mp.contains(node->right)){
                s.push(node->right);
            }else{
                s.pop();
                int lh = mp[node->left];
                int rh = mp[node->right];
                mp[node]= max(lh,rh)+1;
                ans = ans && abs(lh-rh)<=1;
            }
        }
        return ans;
    }
};
