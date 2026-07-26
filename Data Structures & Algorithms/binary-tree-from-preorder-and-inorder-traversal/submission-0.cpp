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
    TreeNode* tree(
        vector<int>& preorder,
        vector<int>& inorder,
        int inl,
        int inr,
        int prl,
        int prr,
        unordered_map<int,int> &ip
    ){
        if(inl>inr || prl>prr || inl<0 || prl<0 || inr>=inorder.size() || prr>=preorder.size()){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prl]);
        int inelid = ip[preorder[prl]];
        root->left = tree(preorder,inorder,inl,inelid-1,prl+1,prl+(inelid-inl),ip);
        root->right = tree(preorder,inorder,inelid+1,inr,prl+(inelid-inl+1),prr,ip);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> ip;
        for(int i=0;i<inorder.size();i++){
            ip[inorder[i]]=i;
        }
        int n= preorder.size()-1;
        return tree(preorder,inorder,0,n,0,n,ip);
    }
};
