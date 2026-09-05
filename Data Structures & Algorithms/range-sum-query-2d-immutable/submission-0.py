class NumMatrix:
    
    def __init__(self, matrix: List[List[int]]):
        self.store: List[List[int]] = [[0]*len(matrix[0]) for i in range(0,len(matrix))]
        for i in range(0,len(matrix)):
            for j in range(0,len(matrix[0])):
                up:int = 0
                left: int = 0
                diagonal:int = 0
                if i-1>=0:
                    up = self.store[i-1][j]
                if j-1>=0:
                    left = self.store[i][j-1]
                if i-1>=0 and j-1>=0:
                    diagonal = self.store[i-1][j-1]
                
                self.store[i][j] = matrix[i][j] + up + left - diagonal
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        i1:int = row1
        j1:int = col1
        i2:int = row2
        j2:int = col2

        ans = self.store[i2][j2]
        if i1-1>=0:
            ans-= self.store[i1-1][j2]
        if j1-1>=0:
            ans-= self.store[i2][j1-1]
        if i1-1>=0 and j1-1>=0:
            ans+= self.store[i1-1][j1-1]
        return ans
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)