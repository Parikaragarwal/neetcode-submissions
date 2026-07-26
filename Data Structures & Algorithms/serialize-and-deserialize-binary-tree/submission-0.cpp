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

class Codec {
// private:
// void serializeTree(TreeNode* root,string &s){
//     if(!root){
//         s+="#N#";
//         return;
//     }

//     s.push_back('#');
//     s += to_string(root->val);
//     s.push_back('#');
//     serializeTree(root->left,s);
//     serializeTree(root->right,s);
// }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans ="";
        if(!root){
            return "";
        }
        // stack<TreeNode*> s;
        // s.push(root);
        // while(!s.empty()){
        //     TreeNode* node = s.top();
        //     s.pop();
        //     ans+=to_string(node->val);
        //     ans+="#";
        //     if(node->right){
        //         s.push(node->right);
        //     }else{
        //         ans+="#N#";
        //     }
        //     if(node->left){
        //         s.push(node->left);
        //     }else{
        //         ans+="#N#";
        //     }
        // }
        // return ans;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* el = q.front();
                q.pop();
                if(!el){
                    ans+="#N#";
                }else{
                    ans+=to_string(el->val);
                    ans.push_back('#');
                    q.push(el->left);
                    q.push(el->right);
                }
            }
        }
        return ans;
        // serializeTree(root,ans);
        // return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data==""){
            return NULL;
        }
        queue<TreeNode*> els;
        string ans="";
        for(char ch:data){
            if(ch=='#'){
                if(ans.size()>0)
                {
                if(ans=="N")
                els.push(NULL);
                else
                els.push((new TreeNode(stoi(ans))));
                ans="";
                }
            }else{
                ans.push_back(ch);
            }
        }
        queue<TreeNode*> process;
        TreeNode* root = els.front();
        els.pop();
        process.push(root);

        while(!process.empty()){
            TreeNode* left = els.front();
            els.pop();
            TreeNode* right = els.front();
            els.pop();
            TreeNode* curr = process.front();
            process.pop();
            curr->left= left;
            curr->right = right;
            if(left){
                process.push(left);
            }
            if(right){
                process.push(right);
            }
        }
        return root;
    }
};
