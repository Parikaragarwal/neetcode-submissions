class Solution {
public:
    int dfs(
        vector<vector<int>> &grid,
        int i,
        int j
    ){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1){
            return 0;
        }

        int di[4]={-1,0,1,0};
        int dj[4]={0,-1,0,1};
        grid[i][j]=0;
        int sum=1;
        for(int k=0;k<4;k++){
            sum+=dfs(grid,i+di[k],j+dj[k]);
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
        
//     }
// };
