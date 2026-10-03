class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        vals = {}
        for i in range(len(order)):
            vals[order[i]] = i

        def compare(a:str,b:str) -> bool:
            n:int = len(a)
            m:int = len(b)

            for i in range(n):
                if i >= m:
                    return False
                if a[i]==b[i]:
                    continue
                else:
                    return vals[a[i]]<=vals[b[i]]

            return True
                
        
        for i in range(len(words)-1):
            if not compare(words[i],words[i+1]):
                return False
        return True