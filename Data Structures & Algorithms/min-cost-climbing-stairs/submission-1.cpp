class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();
       if(n==1){
        return cost[0];
       }
       if(n==2){
        return min(cost[0],cost[1]);
       }
       cost.push_back(0);
       for(int i=2;i<=n;i++){
        cost[i]+=min(cost[i-1],cost[i-2]);
       }
       return cost[n];
    }
};
