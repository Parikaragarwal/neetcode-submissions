class Solution {
public:
    void dfs(
        vector<vector<char>> &grid,
        int i,
        int j
    ){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1'){
            return;
        }

        int di[4]={-1,0,1,0};
        int dj[4]={0,-1,0,1};
        grid[i][j]='x';
        for(int k=0;k<4;k++){
            dfs(grid,i+di[k],j+dj[k]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};
