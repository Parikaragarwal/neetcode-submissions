class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n: int = len(stoneValue)
        # dpa = [-1]*n
        # dpb = [-1]*n

        # def turn(id, alice):
        #     if id == n:
        #         return 0
        #     ans = None
        #     if alice:
        #         if dpa[id]!=-1:
        #             return dpa[id]
        #         ans = -10000000000000
        #         sum = 0
        #         for i in range(id, min(n, id + 3)):
        #             sum += stoneValue[i]
        #             ans = max(ans, sum + turn(i+1, False))
        #         dpa[id]=ans
        #     else:
        #         if dpb[id]!=-1:
        #             return dpb[id]
        #         ans = 100000000000000
        #         sum = 0
        #         for i in range(id, min(n, id + 3)):
        #             sum += stoneValue[i]
        #             ans = min(ans, turn(i+1, True) - sum)
        #         dpb[id]=ans
        #     return ans

        # val = turn(0, True)
        # if val == 0:
        #     return "Tie"
        # elif val < 0:
        #     return "Bob"
        # else:
        #     return "Alice"


        
        # dp = [-1]*(n+1)
        # dp[n]=0
        # def dfs(i):
        #     if dp[i]!=-1:
        #         return dp[i]
        #     sum=stoneValue[i]
        #     ans = sum-dfs(i+1)
        #     for j in range(i+1,min(n,i+3)):
        #         sum+= stoneValue[j]
        #         ans = max(ans,sum-dfs(j+1))
        #     dp[i]=ans
        #     return ans

        # val = dfs(0)
        
        dp = [0]*(n+1)
        dp[n]=0
        for i in range(n-1,-1,-1):
            sum = stoneValue[i]
            dp[i]=sum-dp[i+1]
            for j in range(i+1,min(i+3,n)):
                sum+=stoneValue[j]
                dp[i] = max(dp[i],sum-dp[j+1])
        val = dp[0]

        if val==0:
            return "Tie"
        elif val<0:
            return "Bob"
        else:
            return "Alice"
        
