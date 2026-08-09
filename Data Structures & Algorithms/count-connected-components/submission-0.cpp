class DSU{
private:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;
public:
    int components;
    DSU(vector<int> &els){
        for(int el:els){
            parent[el]=el;
            rank[el]=0;
        }
        components = els.size();
    }

    int find(int el){
        // unordered_set<int> children;
        // while(parent[el]!=el){
        //     el=parent[el];
        //     children.insert(el);
        // }
        // for(int child:children){
        //     parent[child]=el;
        // }
        // return el;
        if(parent[el]!=el)

        parent[el]=find(parent[el]);
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
        if(rank[oldr]==rank[newr]){
            rank[newr]=rank[oldr]+1;
        }
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> els;
        for(int i=0;i<n;i++){
            els.push_back(i);
        }
        DSU dsu(els);
        for(const auto &edge:edges){
            dsu.unionRank(edge[0],edge[1]);
        }
        return dsu.components;
    }
};
