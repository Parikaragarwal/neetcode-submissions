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

        vector<pair<int,int>> go = {
            {i-1,j},
            {i,j-1},
            {i+1,j},
            {i,j+1}
        };
        grid[i][j]='x';
        for(const auto g:go){
            dfs(grid,g.first,g.second);
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
