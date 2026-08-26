class Solution {
public:
    int dist(
        string &s,
        string &t,
        int i,
        int j,
        vector<vector<int>> &dp
    ){
        int n = s.size();
        int m = t.size();

       if(j==m || i==n){
        return max(n-i,m-j);
       }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]!=t[j]){
            return dp[i][j]=1+min(
                dist(s,t,i+1,j,dp),
                min(dist(s,t,i,j+1,dp),
                dist(s,t,i+1,j+1,dp))
            );
        }else{
            return dp[i][j]=dist(s,t,i+1,j+1,dp);
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return dist(word1,word2,0,0,dp);

        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<=n;i++){
        //     dp[i][m]=n-i;
        // }
        // for(int j=0;j<=m;j++){
        //     dp[n][j]=m-j;
        // }
        // for(int i=n-1;i>=0;i--){
        //     for(int j=m-1;j>=0;j--){
        //         if(word1[i]==word2[j]){
        //             dp[i][j]=dp[i+1][j+1];
        //         }else{
        //             dp[i][j]=1+min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
        //         }
        //     }
        // }
        // return dp[0][0];

        vector<int> dp(m+1,0);
        for(int j=0;j<=m;j++){
            dp[j]=m-j;
        }
        for(int i=n-1;i>=0;i--){
            int bl=n-(i+1);
            dp[m]=n-i;
            for(int j=m-1;j>=0;j--){
                int nbl = dp[j];
                if(word1[i]==word2[j]){
                    dp[j]=bl;
                }else{
                    dp[j]=1+min(dp[j+1],min(dp[j],bl));
                }
                bl = nbl;
            }
        }
        return dp[0];
    }
};
