class Solution:
    def integerBreak(self, num: int) -> int:
        # dp:list[int] = [-1]*(num+1)
        # dp[1]=1

        # def dfs(n):
        #     if dp[n]!=-1:
        #         return dp[n]
        #     ans = None
        #     if n==num:
        #         ans = 0
        #     else:
        #         ans = n
        #     for i in range(1,n//2+1):
        #         ans = max(ans,dfs(i)*dfs(n-i))
        #     dp[n]=ans
        #     return ans

        # return dfs(num)

        n: int = num
        if n == 2:
            return 1
        dp: List[int] = [i for i in range(0, n + 1)]
        dp[2] = 1
        dp[n] = 0

        for i in range(3, n + 1):
            end: int = i // 2 + 1
            for j in range(1, end):
                dp[i] = max(dp[i], dp[i - j] * dp[j], dp[i - j] * j, j, (i - j) * dp[j],(i-j)*j)
        return dp[num]
