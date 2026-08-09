class DSU{
private:
    vector<int> parent;
    vector<int> rank;
public:
    int components;
    DSU(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i);
            rank.push_back(0);
        }
        components = n;
    }

    int find(int el){
        if(parent[el]!=el){
            parent[el]=find(parent[el]);
        }
        return parent[el];
    }

    bool unionRank(int a,int b){
        int pa = find(a);
        int pb = find(b);
        if(pa==pb){
            return false;
        }
        components--;
        const auto [newr,oldr] = rank[pa]>rank[pb]?tie(pa,pb):tie(pb,pa);
        parent[oldr]=newr;
        if(rank[pa]==rank[pb]){
            rank[newr]=rank[oldr]+1;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for(const auto &edge:edges){
            int cand = max(edge[0],edge[1]);
            n = max(cand,n);
        }
        DSU dsu(n+1);
        vector<int> ans;
        for(const auto &edge:edges){
            if(!dsu.unionRank(edge[0],edge[1])){
                ans = edge;
            }
        }
        return ans;
    }
};
