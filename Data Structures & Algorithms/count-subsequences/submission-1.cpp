class Solution {
public:
    int dist(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int base = 0;
        if(j==0){
            base = 1;
        }
        if(s[i]==t[j]){
            return dp[i][j]=base+dist(s,t,i-1,j,dp)+dist(s,t,i-1,j-1,dp);
        }else{
            return dp[i][j]=dist(s,t,i-1,j,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up=i-1>=0?dp[i-1][j]:0;
                int left=(i-1>=0 && j-1>=0)?dp[i-1][j-1]:0;
                if(s[i]==t[j]){
                    int base = 0;
                    if(j==0){
                        base = 1;
                    }
                    dp[i][j]=base+up+left;
                }else{
                    dp[i][j]=up;
                }
            }
        }
        return dp[n-1][m-1];
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return dist(s,t,n-1,m-1,dp);
    }
};
