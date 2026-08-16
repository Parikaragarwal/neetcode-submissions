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
        const int INF = 1e9;
        if(amount==0){
            // ans = min(ans,taken);
            return 0;
        }
        if(n<0 || amount<0){
           return INF;
        }
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }
        int coin = coins[n];
        int size = amount/coin;
        int ans = INF;
        // for(int i=0;i<=size;i++){
        //   ans = min(ans,i+change(coins,amount-i*coin,n-1,dp));
        // }
        return dp[n][amount] = min(
            1+change(coins,amount-coin,n,dp),
            change(coins,amount,n-1,dp)
        );
        // return dp[n][amount] = ans;
    }
    int finddp(int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return (int)1e9;
        }

        return dp[i][j];
    }
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;
        if(amount==0){
            return 0;
        }
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // int ans = change(coins,amount,n-1,dp);
        // return ans==INF?-1:ans;

        vector<vector<int>> dp(amount+1,vector<int>(n,0));
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = min(
                    1+finddp(i-coins[j],j,dp),
                    finddp(i,j-1,dp)
                    );
            }
        }
        return dp[amount][n-1]>=(int)1e9?-1:dp[amount][n-1];
    }
};
