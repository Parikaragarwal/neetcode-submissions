struct Node{
    char val;
    bool wordend;
    unordered_map<char,Node*> children;
};
class PrefixTree {
public:
    Node *root;
    PrefixTree() {
        root = new Node;
        root->val = '\0';
        root->wordend=false;
    }
    
    void insert(string word) {
        Node *curr=root;
        for(char ch:word){
            if(!curr->children.contains(ch)){
            Node *childnode = new Node;
            childnode->val=ch;
            childnode->wordend=false;
            curr->children[ch]=childnode;
            }

            curr = curr->children[ch];
        }
        curr->wordend=true;
    }
    
    bool search(string word) {
        Node *curr = root;
        for(char ch:word){
            if(!curr->children.contains(ch)){
                return false;
            }
            curr=curr->children[ch];
        }
        return curr->wordend;
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        for(char ch:prefix){
            if(!curr->children.contains(ch)){
                return false;
            }
            curr=curr->children[ch];
        }
        return true;
    }
};


class Solution {
public:
    void backtrack(
        vector<vector<char>> &board,
        vector<string> &ans,
        Node *root,
        string &cand,
        int i,
        int j,
        unordered_set<string> &added
    ){
        int n=board.size();
        int m=board[0].size();
        if(i<0 || j<0 || i>=n || j>=m || !root->children.contains(board[i][j])){
            return;
        }

        Node *curr = root->children[board[i][j]];
        cand.push_back(curr->val);

        if(curr->wordend && !added.contains(cand)){
            added.insert(cand);
            ans.push_back(cand);
        }
        vector<pair<int,int>> go = {
            {i-1,j},
            {i,j-1},
            {i,j+1},
            {i+1,j}
        };
        for(const auto &g:go){
            char val = board[i][j];
            board[i][j]='#';
            backtrack(board,ans,curr,cand,g.first,g.second,added);
            board[i][j]=val;
        }
        cand.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTree *trie = new PrefixTree();
        for(const string &word:words){
            trie->insert(word);
        }
        vector<string> ans;
        string cand = "";
        unordered_set<string> added;
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                backtrack(board,ans,trie->root,cand,i,j,added);
            }
        }
        return ans;
    }
};
