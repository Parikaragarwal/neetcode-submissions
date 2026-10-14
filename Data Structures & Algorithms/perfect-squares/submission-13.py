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
        n:int = num
        while n%4==0:
            n=n//4
        if (n-7)%8==0:
            return 4
        
        root:int = int(num**0.5)
        if root*root==num:
            return 1
        
        i:int = 1
        j:int = root

        while i<=j:
            cand:int = i*i + j*j
            if cand==num:
                return 2
            elif cand<num:
                i+=1
            else:
                j-=1
        
        return 3
        
        # dp = [num+1]*(num+1)
        # dp[0]=0
        # root = int(num**0.5)

        # for i in range(0,num):
        #     for j in range(1,root+1):
        #         if i+j*j<=num:
        #             dp[i+j*j] = min(dp[i+j*j],1+dp[i])
    
        # return dp[num]