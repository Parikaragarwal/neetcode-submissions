class Solution {
public:
    void dfs(
        vector<vector<pair<int,int>>> &nei,
        unordered_set<int> &visited,
        int curr,
        int k,
        int dst,
        int currcost,
        int &ans
    ){
        if(k==0 || currcost>ans){
            return;
        }

        if(curr==dst){
            ans = min(ans,currcost);
            return;
        }
        visited.insert(curr);
        for(const auto &[next,cost]:nei[curr]){
            if(!visited.count(next) && k>0)
            dfs(nei,visited,next,k-1,dst,currcost+cost,ans);
        }
        visited.erase(curr);
    }
    int findCheapestPrice(
        int n,
        vector<vector<int>>& flights,
        int src, int dst, int k
        ) {

      vector<vector<pair<int,int>>> nei(n);
      for(const auto &flight:flights){
        int a = flight[0];
        int b = flight[1];
        int cost = flight[2];

        nei[a].push_back({b,cost});
      }

      unordered_set<int> visited;
      int ans = INT_MAX;
      dfs(nei,visited,src,k+2,dst,0,ans);
      if(ans==INT_MAX){
        return -1;
      }else{
        return ans;
      }
    }
};
