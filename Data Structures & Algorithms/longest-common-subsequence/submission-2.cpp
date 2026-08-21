class Solution {
public:
    int lcs(string &s1,string &s2,int i,int j,
    vector<vector<int>> &dp){
        int n = s1.size();
        int m = s2.size();

        if(i==n || j==m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]= 1+lcs(s1,s2,i+1,j+1,dp);
        }
        return dp[i][j]= max(lcs(s1,s2,i,j+1,dp),lcs(s1,s2,i+1,j,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int l=n+m-2;l>=0;l--){
            int i = max(l-(m-1),0);
            int j = min(l,m-1);

            //while(i>=0 && j>=0 && i<n && j<m)
            while(i<n && j>=0){
                int ans = 0;
                if(text1[i]==text2[j]){
                    ans=1;
                    if(i+1<n && j+1<m){
                        ans+=dp[i+1][j+1];
                    }
                }else{
                    ans = 0;
                    if(i+1<n){
                        ans= dp[i+1][j];
                    }
                    if(j+1<m){
                        ans = max(ans,dp[i][j+1]);
                    }
                }
                dp[i][j]=ans;
                i++;
                j--;
            }
        }
        return dp[0][0];
        
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return lcs(text1,text2,0,0,dp);
    }
};
