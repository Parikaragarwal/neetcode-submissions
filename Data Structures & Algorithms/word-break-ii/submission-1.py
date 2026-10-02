class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        dictionary = set(wordDict)
        end:int = len(s)
        ans:List[str] = []
        def sentences(start:int,curr:List[str]):
            word:str = ""
            if start==end:
                ans.append(" ".join(curr))
                return
            
            for i in range(start,end):
                word+=s[i]
                if word in dictionary:
                    curr.append(word)
                    sentences(i+1,curr)
                    curr.pop()
        
        curr:List[str] = []
        sentences(0,curr)
        return ans