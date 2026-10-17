class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        size:int = len(piles)
        # cache = {}
        # def play(start,end):
        #     if start>end:
        #         return 0
        #     if (start,end) in cache:
        #         return cache[(start,end)]
            
        #     ans = max(piles[start]+play(start+1,end),piles[end]+play(start,end-1))
        #     cache[(start,end)] = ans
        #     return ans
            
        
        # val:int = play(0,len(piles)-1)
        # return val>=0

        dp = [[0]*size for _ in range(size)]
        for i in range(size):
            for j in range(0,size-i):
                a = 0
                b = 0
                if i+1<size:
                    a= dp[i+1][j]
                if j-1>=0:
                    b= dp[i][j-1]

                dp[i][j] =max(a,b)
        val:int = dp[0][size-1]
        return val>=0





