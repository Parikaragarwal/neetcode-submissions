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
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // return choices(coins,amount,0,dp);


        vector<vector<int>> dp(amount+1,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                int take = i-coins[j]<0?0:dp[i-coins[j]][j];
                int notake = j-1<0?0:dp[i][j-1];
                dp[i][j]= take+notake;
            }
        }
        return dp[amount][n-1];
        // int ans = 0;
        // queue<pair<int,int>> q;
        // q.push({amount,0});
        // while(!q.empty()){
        //     auto [amt,start] = q.front();
        //     q.pop();
        //     for(int i=start;i<n;i++){
        //         int coin = coins[i];
        //         if(amt-coin==0){
        //             ans++;
        //         }else if(amt-coin>0){
        //             q.push({amt-coin,i});
        //         }
        //     }
        // }
        // return ans;
    }
};
