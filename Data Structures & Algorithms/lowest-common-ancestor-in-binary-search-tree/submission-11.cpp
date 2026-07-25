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

    bool checkExists(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*& ans,
    unordered_map<TreeNode*,bool> &containsP,
    unordered_map<TreeNode*,bool> &containsQ
    ){
        if(!root){
            return false;
        }
        if(ans){
            return true;
        }

        if(
            containsP[root]
            && 
            containsQ[root]
            ){
                if(!checkExists(root->left,p,q,ans,containsP,containsQ)
                 &&
                  !checkExists(root->right,p,q,ans,containsP,containsQ))
                ans=root;

                return true;
            }else{
                return false;
            }
            
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TreeNode* ans = NULL;
        // unordered_map<TreeNode*,bool> containsP;
        // unordered_map<TreeNode*,bool> containsQ;
        // containsP[NULL]=false;
        // containsQ[NULL]=false;
        // checkOneExists(root,p,containsP);
        // checkOneExists(root,q,containsQ);
        // checkExists(root,p,q,ans,containsP,containsQ);
        // return ans;

        TreeNode* curr = root;
        
        while(true){
        if(!curr){
            return curr;
        }
        int a=curr->val;
        int b=p->val;
        int c=q->val;
            if(a<b && a<c){
                curr=curr->right;
            }else if(a>b && a>c){
                curr=curr->left;
            }else{
                return curr;
            }
        }
        return root;
    }
};
