class Solution {
public:
    bool match(
        string &s,
        string &p,
        int i,
        int j,
        vector<vector<int>> &dp
    ){
        int n = s.size();
        int m = p.size();
        if(i==n || j>=m){
            if(j+1<m && p[j+1]=='*'){
                return match(s,p,i,j+2,dp);
            }
            return i==n && j==m;
        }
        if(dp[i][j]!=-1){
            return (bool)dp[i][j];
        }
        if(j+1<m && p[j+1]=='*'){
            bool ans = match(s,p,i,j+2,dp);
            if(s[i]==p[j] || p[j]=='.'){
                ans = ans || match(s,p,i+1,j,dp);
            }
            return dp[i][j]=(int)ans;
        }else{
            if(s[i]==p[j] || p[j]=='.'){
                return dp[i][j]=(int)match(s,p,i+1,j+1,dp);
            }else{
                return dp[i][j]=(int)false;
            }
        }

    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return match(s,p,0,0,dp);

        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[n][m]=true;
        for(int j=m-1;j>=0;j--){
            dp[n][j]=j+1<m && p[j+1]=='*' && j+2<=m && dp[n][j+2];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){

            if(j+1<m && p[j+1]=='*'){
                bool ans = dp[i][j+2];
                    if(s[i]==p[j] || p[j]=='.'){
                     ans = ans || dp[i+1][j];
                    }
                dp[i][j]=ans;
            }else{
                if(s[i]==p[j] || p[j]=='.'){
                  dp[i][j]=dp[i+1][j+1];
                } else{
                  dp[i][j]=false;
                }
            }

            }
        }
        return dp[0][0];
    }
};
