class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a=a[::-1]
        b=b[::-1]

        an:int = len(a)
        bn:int = len(b)
        c:int = 0
        ans:List[str] = []

        i:int = 0
        while i<an or i<bn or c>0:
            
            f = int(a[i]) if i<an else 0
            s = int(b[i]) if i<bn else 0
            val = f^s^c
            c = (f&s) + (c&(f^s))
            ans.append(str(val))
            i+=1

        return "".join(ans)[::-1]