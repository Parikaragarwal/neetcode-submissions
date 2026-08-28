class Solution {
private:
   int mx(int a,int b,int c,int d){
    return max(max(max(a,b),c),d);
   }
public:
    int dfs(
        vector<vector<int>> &grid,
        int i1,int j1,
        int i2,
        vector<vector<vector<int>>> &dp
    ){
        int j2 = i1+j1-i2;
        int n = grid.size();
        int ans;
        if(i1==n || j1==n || i2==n || j2==n || grid[i1][j1]==-1 || grid[i2][j2]==-1 || j2<0){
            return -1e9;
        }
        if(i1==n-1 && j1==n-1 && i2==n-1 && j2==n-1){
            return dp[i1][j1][i2]=grid[i1][j1];
            // return dp[i1][j1][i2];
        }
        
        if(dp[i1][j1][i2]!=INT_MIN){
            return dp[i1][j1][i2];
        }
        if(i1==i2 && j1==j2){
            ans=grid[i1][j1];
        }else{
            ans = grid[i1][j1]+grid[i2][j2];
        }
        return dp[i1][j1][i2]=ans + mx(
            dfs(grid,i1+1,j1,i2+1,dp),
            dfs(grid,i1,j1+1,i2,dp),
            dfs(grid,i1+1,j1,i2,dp),
            dfs(grid,i1,j1+1,i2+1,dp)
        );
    }
    int cherryPickup(vector<vector<int>>& grid) {
       int n = grid.size();
       vector<vector<int>> cell(n,vector<int>(n,INT_MIN));
       vector<vector<vector<int>>> dp(n,cell);
       int ans = dfs(grid,0,0,0,dp);
       return max(ans,0);
    }
};