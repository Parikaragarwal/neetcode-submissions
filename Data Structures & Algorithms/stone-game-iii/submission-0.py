class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n: int = len(stoneValue)
        dpa = [-1]*n
        dpb = [-1]*n

        def turn(id, alice):
            if id == n:
                return 0
            ans = None
            if alice:
                if dpa[id]!=-1:
                    return dpa[id]
                ans = -10000000000000
                sum = 0
                for i in range(id, min(n, id + 3)):
                    sum += stoneValue[i]
                    ans = max(ans, sum + turn(i+1, False))
                dpa[id]=ans
            else:
                if dpb[id]!=-1:
                    return dpb[id]
                ans = 100000000000000
                sum = 0
                for i in range(id, min(n, id + 3)):
                    sum += stoneValue[i]
                    ans = min(ans, turn(i+1, True) - sum)
                dpb[id]=ans
            return ans

        val = turn(0, True)
        if val == 0:
            return "Tie"
        elif val < 0:
            return "Bob"
        else:
            return "Alice"
