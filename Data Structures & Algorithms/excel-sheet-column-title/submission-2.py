class Solution:
    def convertToTitle(self, n: int) -> str:
        ans:List[str] = []
        while n!=0:
            n=n-1
            s = chr(ord('A')+n%26)
            ans.append(s)
            n=n//26
        ans.reverse()
        return "".join(ans)