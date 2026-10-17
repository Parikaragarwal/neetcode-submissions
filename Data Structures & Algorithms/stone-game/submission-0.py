class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        def play(start,end):
            if start<=end:
                return 0
            return max(piles[start]+play(start+1,end),piles[end]+play(start,end-1))
        val:int = play(0,len(piles)-1)
        return val>=0