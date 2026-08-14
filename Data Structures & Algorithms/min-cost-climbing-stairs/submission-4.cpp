class Solution {
private:
unordered_map<int,int> dp;
public:
    int mincost(int n,vector<int> &cost){
        if(n<0){
            return 0;
        }
        if(dp.contains(n)){
            return dp[n];
        }
        return dp[n] = cost[n]+min(mincost(n-1,cost),mincost(n-2,cost));
    }
    int minCostClimbingStairs(vector<int> &cost) {
       int n = cost.size();
       if(n==1){
        return cost[0];
       }
       if(n==2){
        return min(cost[0],cost[1]);
       }
       return min(mincost(n-1,cost),mincost(n-2,cost));
    //    cost.push_back(0);
    //    for(int i=2;i<=n;i++){
    //     cost[i]+=min(cost[i-1],cost[i-2]);
    //    }
    //    return cost[n];

    }
};
