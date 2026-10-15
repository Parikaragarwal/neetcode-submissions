class Solution:
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dp = [[0]*m for _ in range(n)]
        dp[n-1][m-1]=1

        if n==1 and m==1 and grid[0][0]==1:
            return 0

        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                if grid[i][j]==1:
                    continue
                if i+1<n and grid[i+1][j]!=1:
                    dp[i][j]+=dp[i+1][j]
                if j+1<m and grid[i][j+1]!=1:
                    dp[i][j]+=dp[i][j+1]
        return dp[0][0]
                
                