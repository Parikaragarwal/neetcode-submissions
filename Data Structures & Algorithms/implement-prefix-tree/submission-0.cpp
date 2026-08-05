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
