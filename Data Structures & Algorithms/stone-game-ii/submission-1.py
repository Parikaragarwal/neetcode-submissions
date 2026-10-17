class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        totalsum = sum(piles)
        n:int = len(piles)

        cache = {}
        prefix = [0]*(n+1)
        for i in range(1,n+1):
            prefix[i]=prefix[i-1]+piles[i-1]
        
        def dfs(id,M):
            if id==n:
                return 0
            if (id,M) in cache:
                return cache[(id,M)]

            res = float("-inf")
            for i in range(1,min(n-id,2*M)+1):
                res = max(res,prefix[i+id]-prefix[id]-dfs(id+i,max(M,i)))
            cache[(id,M)]=res
            return res
        
        return (totalsum+dfs(0,1))//2