/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
bool checkOneExists(TreeNode* root,TreeNode* p,
    unordered_map<TreeNode*,bool> &containsP){
        if(!root){
            return false;
        }
        auto it = containsP.find(root);
        if(it!=containsP.end()){
            return it->second;
        }
        if(root==p){
            containsP[root]=true;
        }
        containsP[root]=checkOneExists(root->left,p,containsP) ||
         checkOneExists(root->right,p,containsP) || containsP[root];
        return containsP[root];
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        unordered_map<TreeNode*,bool> containsP;
        unordered_map<TreeNode*,bool> containsQ;
        containsP[NULL]=false;
        containsQ[NULL]=false;
        checkOneExists(root,p,containsP);
        checkOneExists(root,q,containsQ);

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            for(int i=0;i<que.size();i++){
                TreeNode* cand = que.front();
                que.pop();
                if(containsP[cand] && containsQ[cand]){
                    ans=cand;
                    if(cand->left){
                        que.push(cand->left);
                    }
                    if(cand->right){
                        que.push(cand->right);
                    }
                }
            }
        }
        return ans;
    }
};