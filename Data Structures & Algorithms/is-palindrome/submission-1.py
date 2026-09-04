class Solution:
    def isAlphaNumeric(self,s:str) -> bool:
        alnu = "qwertyuiopasdfghjkklzxcvbnm1234567890"
        charnum = set(alnu)
        return s in charnum

    def isPalindrome(self, s: str) -> bool:
        n:int = len(s)
        s = s.lower()
        l:int = 0
        r:int = n-1
        while(l<r):
            if not self.isAlphaNumeric(s[l]):
                l+=1
                continue
            if not self.isAlphaNumeric(s[r]):
                r-=1
                continue
            
            if s[l]!=s[r]:
                return False
            l+=1
            r-=1

        return True