class TimeMap {
    unordered_map<string,vector<pair<string,int>> > timeMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({value,timestamp});
    }
    
    string get(string key, int t) {
        auto it=timeMap.find(key);
        if(it==timeMap.end()){
            return "";
        }

        // vector<pair<string,int>> cand = it->second;
        int start=0;
        int end=it->second.size()-1;
        if(it->second[start].second>t){
            return "";
        }
        string ans;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            auto currEl = it->second[mid];

            if(currEl.second==t){
                return currEl.first;
            }else if(currEl.second>t){
                end=mid-1;
            }else{
                ans=currEl.first;
                start=mid+1;
            }
        }
        return ans;
    }
};
