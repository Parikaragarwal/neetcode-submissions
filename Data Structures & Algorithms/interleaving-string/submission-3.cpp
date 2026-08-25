class Solution {
public:
    bool interleave(
        string &s1,
        string &s2,
        string &s3,
        int i,
        int j,
        vector<vector<int>> &dp
    ){
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(i+j==n3){
            return true;
        }
        bool ans = false;
        if(i<n1 && j<n2 && dp[i][j]!=-1){
            return (bool)dp[i][j];
        }
        if(i<n1 && s1[i]==s3[i+j]){
            ans = ans || interleave(s1,s2,s3,i+1,j,dp);
        }
        if(j<n2 && s2[j]==s3[i+j]){
            ans = ans || interleave(s1,s2,s3,i,j+1,dp);
        }
        
        return dp[i][j]=(int)ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
       int n1 = s1.size();
       int n2 = s2.size();
       int n3 = s3.size();

       if(n1+n2!=n3){
        return false;
       }
    //    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    //    return interleave(s1,s2,s3,0,0,dp);

    vector<vector<bool>> dp(n1+1,vector<bool>(n2+1,false));
    dp[n1][n2]=true;
    for(int i=n1;i>=0;i--){
        for(int j=n2;j>=0;j--){
            int ans = false;
            if(i+j==n3){
                continue;
            }
            if(i<n1 && s1[i]==s3[i+j]){
                ans = ans || dp[i+1][j];
            }
            if(j<n2 && s2[j]==s3[i+j]){
                ans = ans || dp[i][j+1];
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][0];
    }
};
