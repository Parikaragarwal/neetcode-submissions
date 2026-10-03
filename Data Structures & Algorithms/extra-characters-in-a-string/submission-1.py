class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        
        dictionary = set(dictionary)
        end:int = len(s)

        mem:List[int] = [-1 for _ in range(len(s))]

        def minchars(start:int) -> int:
            
            if start==end:
                return 0
            if mem[start]!=-1:
                return mem[start]

            ans:int = 1 + minchars(start+1)

            for i in range(start,end):
                if s[start:i+1] in dictionary:
                    ans = min(ans,minchars(i+1))

            mem[start]=ans
            return ans

        return minchars(0)