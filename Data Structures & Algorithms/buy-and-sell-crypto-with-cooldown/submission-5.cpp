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
        int ans = trade(prices,start+1,graph);

        for(int nei:graph[start]){
            ans = max(ans,prices[nei]-
            prices[start]+trade(prices,nei+2,graph));
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
