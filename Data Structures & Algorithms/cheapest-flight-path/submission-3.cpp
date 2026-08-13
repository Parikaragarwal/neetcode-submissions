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

        nei[a].emplace_back(b,cost);
      }

      queue<vector<int>> q;
      q.push({src,0});
      int ans = INT_MAX;

      for(int l=0;l<k+1;l++){
        int size = q.size();
        unordered_map<int,int> nxtlyr;
        for(int i=0;i<size;i++){
          auto vec = q.front();
          q.pop();
          int curr = vec[0];
          int dis = vec[1];

          for(const auto &[nb,tc]:nei[curr]){
            if(!nxtlyr.contains(nb)){
              nxtlyr[nb]=dis+tc;
            }else{
              nxtlyr[nb] = min(nxtlyr[nb],dis+tc);
            }
            // q.push({nb,dis+tc});
            if(nb==dst){
              ans = min(ans,dis+tc);
            }
          }
        }

        for(auto [epa,dha]:nxtlyr){
          q.push({epa,dha});
        }
      }
      return ans==INT_MAX?-1:ans;


      // unordered_set<int> visited;
      // int ans = INT_MAX;
      // dfs(nei,visited,src,k+2,dst,0,ans);
      // if(ans==INT_MAX){
      //   return -1;
      // }else{
      //   return ans;
      // }
    }
};
