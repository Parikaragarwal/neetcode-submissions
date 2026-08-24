class Solution {
public:
    int choices(
        vector<int> &coins,
        int amount,
        int id,
        vector<vector<int>> &dp
    ){
        int n = coins.size();
        if(amount==0){
            return 1;
        }
        if(amount<0 || id>=n){
            return 0;
        }
        if(dp[id][amount]!=-1){
            return dp[id][amount];
        }
        return dp[id][amount]=(choices(coins,amount-coins[id],id,dp)+choices(coins,amount,id+1,dp));
    }
    int change(int amount, vector<int>& coins) {
        if(amount==0){
            return 1;
        }
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return choices(coins,amount,0,dp);
    }
};
