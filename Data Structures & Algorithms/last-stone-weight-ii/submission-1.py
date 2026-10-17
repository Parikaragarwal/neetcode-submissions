class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        total:int = sum(stones)
        target:int = (total+1)//2
        n:int = len(stones)

        dp = {}
        def dfs(id,currsum):
            if id==n or currsum>=target:
                return abs(currsum-(total-currsum))
            if (id,currsum) in dp:
                return dp[(id,currsum)]
            ans = min(dfs(id+1,currsum),dfs(id+1,currsum+stones[id]))
            dp[(id,currsum)]=ans
            return ans

        return dfs(0,0)
