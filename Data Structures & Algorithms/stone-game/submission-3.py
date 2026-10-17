class Solution:
    def stoneGame(self, piles: List[int]) -> bool:

        cache = {}
        def play(start,end):
            if start>end:
                return 0
            if (start,end) in cache:
                return cache[(start,end)]
            
            ans = max(piles[start]+play(start+1,end),piles[end]+play(start,end-1))
            cache[(start,end)] = ans
            return ans
            
        
        val:int = play(0,len(piles)-1)
        return val>=0