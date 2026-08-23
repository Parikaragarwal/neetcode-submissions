class Solution {
private:
    unordered_map<int,int> dp;
    int trade(
        vector<int> &prices,
        int start,
        vector<vector<int>> &graph
    ){
        int n = prices.size();
        if(start>=n){
            return 0;
        }
        if(dp.contains(start)){
            return dp[start];
        }
        int ans = 0;
        int cand=0;
        for(int i=start;i<n;i++){
            for(int nei:graph[i]){
                cand = max(cand,prices[nei]-
                prices[i]+trade(prices,nei+2,graph));
            }
            ans = max(ans,cand);
        }
        return dp[start]=ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<int,int> dpc;
        dp=dpc;
        int n = prices.size();
        if(n==1){
            return 0;
        }
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prices[j]>prices[i]){
                    graph[i].push_back(j);
                }
            }
        }
        return trade(prices,0,graph);
    }
};
