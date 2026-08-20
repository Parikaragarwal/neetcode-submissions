class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=1;
        int ans = 0;
        for(int j=0;j<m+n-1;j++){
            int di=max(0,j-(m-1));
            int dj=min(j,m-1);
            while(di<n && dj>=0){
                int a=0,b=0;
                if(di-1>=0){
                    a=dp[di-1][dj];
                }
                if(dj-1>=0){
                    b=dp[di][dj-1];
                }
                dp[di][dj]+= a+b;
                di++;
                dj--;
            }
        }
        return dp[n-1][m-1];
    }
};
