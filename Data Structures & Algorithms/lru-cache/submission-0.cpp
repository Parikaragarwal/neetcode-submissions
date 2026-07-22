class LRUCache {
public:
    
    unordered_map<int,int> mp;
    unordered_map<int,list<int>::iterator> lst;
    list<int> ll;
    int cap;

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(!mp.contains(key)){
            return -1;
        }
        ll.erase(lst[key]);
        ll.push_back(key);
        lst[key]=(--ll.end());
        return mp[key];
    }
    
    void put(int key, int value) {
        mp[key]=value;
        if(lst.contains(key)){
            ll.erase(lst[key]);
        }
        ll.push_back(key);
        lst[key]=(--ll.end());
        if(mp.size()>cap){
            mp.erase(*ll.begin());
            lst.erase(*ll.begin());
            ll.pop_front();
        }
    }
};
