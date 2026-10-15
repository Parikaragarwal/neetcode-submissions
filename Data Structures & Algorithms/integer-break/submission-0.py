class Solution:
    
    def integerBreak(self, num: int) -> int:
        dp:list[int] = [-1]*(num+1)
        dp[1]=1

        def dfs(n):
            if dp[n]!=-1:
                return dp[n]
            ans = None
            if n==num:
                ans = 0
            else:
                ans = n
            for i in range(1,n):
                ans = max(ans,dfs(i)*dfs(n-i))
            dp[n]=ans
            return ans

        return dfs(num)