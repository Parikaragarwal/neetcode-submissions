struct Node{
    char val;
    bool wordend;
    unordered_map<char,Node*> children;
};
class WordDictionary {
private:
Node *root;

public:
    WordDictionary() {
        root = new Node;
        root->val = '\0';
        root->wordend=false;
    }
    
    void addWord(string word) {
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
    
    bool search(string word,int id=0,Node *start=nullptr) {
        if(!start){
            start=root;
        }
        Node *curr = start;
        for(int i=id;i<word.size();i++){
            char ch= word[i];
            if(ch=='.'){
                bool ans=false;
                for(const auto &it:curr->children){
                    ans=ans || search(word,i+1,it.second);
                    if(ans){
                        return ans;
                    }
                }
                return ans;
            }
            if(!curr->children.contains(ch)){
                return false;
            }
            curr=curr->children[ch];
        }
        return curr->wordend;
    }
};
