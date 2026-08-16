class Solution {
public:
    int change(
        vector<int> &coins,
        int amount,
        int n,
        vector<vector<int>> &dp
        // int taken,
        // int &ans,
    ){
        const int INF = 10e7;
        if(amount==0){
            // ans = min(ans,taken);
            return 0;
        }
        if(n<0){
           return INF;
        }
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }
        int coin = coins[n];
        int size = amount/coin;
        int ans = INF;
        for(int i=0;i<=size;i++){
          ans = min(ans,i+change(coins,amount-i*coin,n-1,dp));
        }
        return dp[n][amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 10e7;
        if(amount==0){
            return 0;
        }
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = change(coins,amount,n-1,dp);
        return ans==INF?-1:ans;
    }
};
