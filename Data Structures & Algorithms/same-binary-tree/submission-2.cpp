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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(!p && !q){
            return true;
        }else if((!p && q)|| (!q && p)){
            return false;
        }

        // return p->val==q->val && 
        // isSameTree(p->left,q->left) && 
        // isSameTree(p->right,q->right);

        stack<TreeNode*> ps;
        stack<TreeNode*> qs;

        ps.push(p);
        qs.push(q);
        while(!ps.empty()){
            TreeNode* node1 = ps.top();
            ps.pop();

            if(qs.empty()){
                return false;
            }

            TreeNode* node2 = qs.top();
            qs.pop();

            if((node1 && !node2) || (node2 && !node1)){
                return false;
            }
            if(node1 && node2 && node1->val!=node2->val){
                return false;
            }

            if(  (node1 && node2 && node1->val==node2->val))
            {
                ps.push(node1->left);
                ps.push(node1->right);
                qs.push(node2->left);
                qs.push(node2->right);
            }
        }
        return true;
    }
};
