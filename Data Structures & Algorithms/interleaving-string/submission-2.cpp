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
       vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));

       return interleave(s1,s2,s3,0,0,dp);
       
    }
};
