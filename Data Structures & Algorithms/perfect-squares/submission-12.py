class Solution:
    def numSquares(self, num: int) -> int:

        # dp = [-1]*(num+1)
        # dp[0]=0

        # def minVal(n:int) ->int:
        #     if dp[n]!=-1:
        #         return dp[n]

        #     root = int(n**0.5)
        #     if n - root*root == 0:
        #         dp[n]=1
        #         return 1
        
        #     ans = n
        #     for i in range(1,root+1):
        #         ans = min(ans,1+minVal(n-i*i))
            
        #     dp[n]=ans
        #     return ans

        # return minVal(num)
        
        dp = [num+1]*(num+1)
        dp[0]=0
        root = int(num**0.5)

        for i in range(0,num):
            for j in range(1,root+1):
                if i+j*j<=num:
                    dp[i+j*j] = min(dp[i+j*j],1+dp[i])
    
        return dp[num]