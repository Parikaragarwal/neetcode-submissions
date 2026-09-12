class Node {
public:
   int key;
   Node *next;
   Node(int val){
    key = val;
    next = NULL;
   }
};
class MyHashSet {
public:
    int mod=1e4+7;
    vector<Node*> hset;
    MyHashSet() {
        for(int i=0;i<mod;i++){
            hset.push_back(new Node(0));
        }
    }
    
    void add(int key) {
        Node *curr = hset[key%mod];
        while(curr->next){
            if(curr->next->key == key){
                return;
            }
            curr = curr->next;
        }
        curr->next = new Node(key);
    }
    
    void remove(int key) {
        Node *curr = hset[key%mod];
        while(curr->next){
            if(curr->next->key == key){
                curr->next = curr->next->next;
                return;
            }
            curr = curr->next;
        }
    }
    
    bool contains(int key) {
        Node *curr = hset[key%mod];
        while(curr->next){
            if(curr->next->key == key){
                return true;
            }
            curr = curr->next;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */