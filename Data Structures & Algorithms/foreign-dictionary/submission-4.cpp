class Solution {
public:
    bool wordcmp(
    string &a,
    string &b,
    unordered_map<char,unordered_set<char>> &nei,
    unordered_map<char,int> &indeg
    ){
        for(int i=0;i<a.size();i++){
            if(i==b.size()){
                return false;
            }
            indeg[a[i]];
            indeg[b[i]];
            if(a[i]!=b[i]){
                if(!nei[a[i]].count(b[i])){
                nei[a[i]].insert(b[i]);
                indeg[b[i]]++;
                }
                return true;
            }
        }
        return true;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> nei;
        unordered_map<char,int> indeg;
        for(string &word:words){
            for(char ch:word){
                indeg[ch];
            }
        }
        for(int i=0;i<words.size()-1;i++){
            if(!wordcmp(words[i],words[i+1],nei,indeg)){
                return "";
            }
        }

        queue<char> q;

        for(const auto it:indeg){
            if(it.second==0){
                q.push(it.first);
            }
        }

        string ans = "";
        while(!q.empty()){
            char el = q.front();
            ans.push_back(el);
            q.pop();
            for(char ch:nei[el]){
                if(--indeg[ch]==0){
                    q.push((ch));
                }
            }
        }
        if(indeg.size()!=ans.size()){
         return "";
        }

        return ans;
    }
};
