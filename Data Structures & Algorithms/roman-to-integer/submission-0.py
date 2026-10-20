class Solution:
    def romanToInt(self, s: str) -> int:
        val = {}
        val["I"] = 1
        val["V"] = 5
        val["X"] = 10
        val["L"] = 50
        val["C"] = 100
        val["D"] = 500
        val["M"] = 1000

        ans: int = 0

        s = s[::-1]
        n: int = len(s)

        spc = {}
        spc['I'] = ['V','X']
        spc['X'] = ['L','C']
        spc['C'] = ['D','M']

        for i in range(n):
            e = s[i]
            if e in spc and i - 1 >= 0 and (s[i - 1] == spc[e][0] or s[i - 1] == spc[e][1]):
                while i < n and s[i] == e:
                    ans -= val[e]
                    i += 1
                i -= 1
            else:
                ans+=val[e]
        
        return ans
            
