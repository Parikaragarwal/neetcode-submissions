class Solution {
private:
bool dfs(
    int i,
    unordered_map<int,vector<int>> &mp,
    unordered_set<int> &visited
    ){
        if(visited.contains(i)){
            return false;
        }
        if(mp[i].empty()){
            return true;
        }

        visited.insert(i);
        for(int n:mp[i]){
            if(!dfs(n,mp,visited)){
                return false;
            }
        }
        visited.erase(i);
        mp[i].clear();
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> mp;
        unordered_set<int> visited;

        for(const auto &el:prerequisites){
            int a = el[0];
            int b = el[1];
            mp[b].push_back(a);
        }

         for(int i=0;i<numCourses;i++){
            if(!dfs(i,mp,visited)){
                return false;
            }
         }

         return true;
    }
};
