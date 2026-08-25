class Solution {
private:
vector<vector<int>> dp;
public:
    int dfs(
        vector<vector<int>> &matrix,
        int id,
        int jd
    ){
        int di[4]={0,-1,0,1};
        int dj[4]={1,0,-1,0};

        int n = matrix.size();
        int m = matrix[0].size();
        if(id>=n || jd>=m || id<0 || jd<0){
            return 0;
        }
        if(dp[id][jd]!=-1){
            return dp[id][jd];
        }
        int ans = 0;
        for(int l=0;l<4;l++){
           int i = id+di[l];
           int j = jd+dj[l];
           if(i>=0 && j>=0 && i<n && j<m && matrix[i][j]>matrix[id][jd]){
            ans=max(ans,dfs(matrix,i,j));
           }
        }
        return dp[id][jd]=1+ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 1;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dpc(n,vector<int>(m,-1));
        dp=dpc;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1)
                ans = max(ans,dfs(matrix,i,j));
            }
        }
        return ans;
    }
};
