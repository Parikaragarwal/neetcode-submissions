struct Node{
    char val;
    bool wordend;
    bool explored;
    unordered_map<char,Node*> children;
};
class PrefixTree {
public:
    Node *root;
    PrefixTree() {
        root = new Node;
        root->val = '\0';
        root->wordend=false;
        root->explored=false;
    }
    
    void insert(string word) {
        Node *curr=root;
        for(char ch:word){
            if(!curr->children.contains(ch)){
            Node *childnode = new Node;
            childnode->val=ch;
            childnode->wordend=false;
            childnode->explored=false;
            curr->children[ch]=childnode;
            }

            curr = curr->children[ch];
        }
        curr->wordend=true;
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
        int j
    ){
        int n=board.size();
        int m=board[0].size();
        if(i<0 || j<0 || i>=n || j>=m || !root->children.contains(board[i][j])){
            return;
        }

        Node *curr = root->children[board[i][j]];
        
        cand.push_back(curr->val);

        if(curr->wordend && !curr->explored){
            ans.push_back(cand);
        }
        curr->explored=true;
        vector<pair<int,int>> go = {
            {i-1,j},
            {i,j-1},
            {i,j+1},
            {i+1,j}
        };
        for(const auto &g:go){
            char val = board[i][j];
            board[i][j]='#';
            backtrack(board,ans,curr,cand,g.first,g.second);
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
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                backtrack(board,ans,trie->root,cand,i,j);
            }
        }
        return ans;
    }
};
