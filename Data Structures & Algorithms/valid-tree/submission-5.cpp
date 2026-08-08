class Solution {
public:
    void dfs(int i,
    unordered_map<int,vector<int>> &mp,
    unordered_set<int> &visited){
        if(visited.contains(i)){
            return;
        }
        visited.insert(i);
        for(int el:mp[i]){
            dfs(el,mp,visited);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }

        unordered_map<int,vector<int>> mp;
        for(const auto &edge:edges){
            int a = edge[0];
            int b = edge[1];
            mp[a].push_back(b);
            mp[b].push_back(a);
        }

        unordered_set<int> vis;
        dfs(0,mp,vis);

        return vis.size()==n;

    }
};
