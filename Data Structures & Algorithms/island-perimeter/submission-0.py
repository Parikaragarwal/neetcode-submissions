class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        row:int = len(grid)
        col:int = len(grid[0])

        di:List[int] = [1,0,-1,0]
        dj:List[int] = [0,1,0,-1]

        def dfs(i,j) -> int:
            if grid[i][j]==-1:
                return 0
            
            grid[i][j]=-1

            nei:int = 0
            ans:int = 4
            for l in range(4):
                ci:int = i+di[l]
                cj:int = j+dj[l]

                if ci>=0 and cj>=0 and ci<row and cj<col and grid[ci][cj]!=0:
                    nei+=1
                    ans+= dfs(ci,cj)

            return ans-nei
        
        for i in range(row):
            for j in range(col):
                if grid[i][j]==1:
                   return dfs(i,j)

        
                

