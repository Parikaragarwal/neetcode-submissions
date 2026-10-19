class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        a = str1 if len(str1) < len(str2) else str2
        b = str1 if a == str2 else str2

        na = len(a)
        nb = len(b)
        if na % nb == 0:
            cand = b[0:nb]
            if cand * (na // nb) == a:
                return cand
        rang = nb//2+1

        for x in range(rang, 0, -1):
            if na % x == 0 and nb % x == 0:
                cand = b[0:x]
                if cand * (nb // x) == b and cand * (na // x) == a:
                    return cand
        return ""
