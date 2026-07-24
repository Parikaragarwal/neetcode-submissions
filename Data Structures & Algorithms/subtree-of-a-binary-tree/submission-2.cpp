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
private:
bool kmp(const string& s1, const string& s2) {
        int n = s1.length();
        int m = s2.length();

        // An empty pattern is always considered a substring
        if (m == 0) return true;
        if (n < m) return false;

        // 1. Precompute the LPS (Longest Prefix Suffix) array
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;

        while (i < m) {
            if (s2[i] == s2[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // 2. Perform the matching
        i = 0; // index for s1
        int j = 0; // index for s2
        while (i < n) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return true; // Match found
            } else if (i < n && s1[i] != s2[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }


void serializeTree(TreeNode* root,string &s){
    if(!root){
        s+="#N#";
        return;
    }

    s.push_back('#');
    s += to_string(root->val);
    s.push_back('#');
    serializeTree(root->left,s);
    serializeTree(root->right,s);
}

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot){
            return true;
        }

        if(!root && subRoot){
            return false;
        }

        // stack<TreeNode*> s;
        // s.push(root);

        // while(!s.empty()){
        //     TreeNode* node = s.top();
        //     s.pop();
        //     if(node->val==subRoot->val && isSameTree(node,subRoot)){
        //         return true;
        //     }
        //     if(node->left){
        //         s.push(node->left);
        //     }
        //     if(node->right){
        //         s.push(node->right);
        //     }
        // }
        // return false;

        string s1="";
        string s2="";
        serializeTree(root,s1);
        serializeTree(subRoot,s2);

        return kmp(s1,s2);
    }
};
