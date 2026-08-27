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
        // return match(s,p,0,0);
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return match(s,p,0,0,dp);
    }
};
