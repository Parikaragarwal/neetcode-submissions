class Solution {
private:
    // unordered_map<int,int> dp;
    // // int trade(
    // //     vector<int> &prices,
    // //     int start,
    // //     vector<vector<int>> &graph
    // // ){
    // //     int n = prices.size();
    // //     if(start>=n){
    // //         return 0;
    // //     }
    // //     if(dp.contains(start)){
    // //         return dp[start];
    // //     }
    // //     int ans = trade(prices,start+1,graph);

    // //     for(int nei:graph[start]){
    // //         ans = max(ans,prices[nei]-
    // //         prices[start]+trade(prices,nei+2,graph));
    // //     }

    // //     return dp[start]=ans;
    // // }

    int buysell(
        vector<int> &prices,
        int curr,
        bool buy,
        vector<vector<int>> &dp
    ){
        int n = prices.size();
        if(curr>=n){
            return 0;
        }
        int i = (int)buy;
        int j = curr;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int cooldown = buysell(prices,curr+1,buy,dp);
        int work;
        if(buy){
            work = buysell(prices,curr+1,!buy,dp)-prices[curr];
        }else{
            work = buysell(prices,curr+2,!buy,dp)+prices[curr];
        }
        return dp[i][j]=max(cooldown,work);
    }
public:
    int maxProfit(vector<int>& prices) {
        // unordered_map<int,int> dpc;
        // dp=dpc;
        int n = prices.size();
        if(n==1){
            return 0;
        }
        vector<vector<int>> dp(2,vector<int>(n,-1));
        // vector<vector<int>> graph(n);
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(prices[j]>prices[i]){
        //             graph[i].push_back(j);
        //         }
        //     }
        // }
        // return trade(prices,0,graph);

        return buysell(prices,0,true,dp);
    }
};
