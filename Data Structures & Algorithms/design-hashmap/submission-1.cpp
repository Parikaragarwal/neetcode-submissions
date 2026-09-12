class Node{
    public:
    int key;
    int val;
    Node* next;

    Node(int keyo,int valo){
        key = keyo;
        val = valo;
        next = NULL;
    }
};
class MyHashMap {
public:
    vector<Node*> mp;
    int mod = 1e4;
    MyHashMap() {
        for(int i=0;i<mod;i++){
            mp.push_back(new Node(0,0));
        }
    }
    
    void put(int key, int value) {
        Node *curr = mp[key%mod];
        while(curr->next){
            if(curr->next->key == key){
                curr->next->val = value;
                return;
            }
            curr = curr->next;
        }
        curr->next = new Node(key,value);
    }
    
    int get(int key) {
        Node *curr = mp[key%mod];
        while(curr->next){
            if(curr->next->key==key){
                return curr->next->val;
            }
            curr=curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        Node *curr = mp[key%mod];
        while(curr->next){
            if(curr->next->key == key){
                curr->next = curr->next->next;
                return;
            }
            curr = curr->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */