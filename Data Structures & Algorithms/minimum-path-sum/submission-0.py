class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                ans = float("inf")
                if i==n-1 and j==m-1:
                    continue
                if i+1<n:
                    ans = min(ans,grid[i+1][j])
                if j+1<m:
                    ans = min(ans,grid[i][j+1])
                
                grid[i][j]+=ans
        
        return grid[0][0]