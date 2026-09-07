class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i1:int = 0
        i2:int = 0
        end1:int = len(word1)
        end2:int = len(word2)

        ans:List = []

        while i1<end1 or i2<end2:
            if i1<end1:
                ans.append(word1[i1])
                i1+=1
            if i2<end2:
                ans.append(word2[i2])
                i2+=1
            
        return "".join(ans)
