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
       
        // Common Part of first 2 solutions
        // TreeNode* ans = NULL;
        // unordered_map<TreeNode*,bool> containsP;
        // unordered_map<TreeNode*,bool> containsQ;
        // containsP[NULL]=false;
        // containsQ[NULL]=false;
        // checkOneExists(root,p,containsP);
        // checkOneExists(root,q,containsQ);


        // Solution 1

        // checkOneExists(root,q,containsQ);
        // checkExists(root,p,q,ans,containsP,containsQ);
        // return ans;


        //Solution 2
        // queue<TreeNode*> que;
        // que.push(root);
        // while(!que.empty()){
        //     for(int i=0;i<que.size();i++){
        //         TreeNode* cand = que.front();
        //         que.pop();
        //         if(containsP[cand] && containsQ[cand]){
        //             ans=cand;
        //             if(cand->left){
        //                 que.push(cand->left);
        //             }
        //             if(cand->right){
        //                 que.push(cand->right);
        //             }
        //         }
        //     }
        // }
        // return ans;


        if(!root || root==p || root==q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left && right){
            return root;
        }else if(left && !right){
            return left;
        }else if(right && !left){
            return right;
        }else{
            return NULL;
        }
    }
};
