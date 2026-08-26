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
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return dist(word1,word2,0,0,dp);
    }
};
