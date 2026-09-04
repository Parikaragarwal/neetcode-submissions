class Solution:
    # def isAlphaNumeric(self,s:str) -> bool:
    #     alnu = "qwertyuiopasdfghjkklzxcvbnm1234567890"
    #     charnum = set(alnu)
    #     return s in charnum

    def isPalindrome(self, s: str) -> bool:
        alnu = "qwertyuiopasdfghjkklzxcvbnm1234567890"
        charnum = set(alnu)
        s = s.lower()

        n:int = len(s)
        l:int = 0
        r:int = n-1
        while(l<r):
            if s[l] not in charnum:
                l+=1
                continue
            if s[r] not in charnum:
                r-=1
                continue
            
            if s[l]!=s[r]:
                return False
            l+=1
            r-=1

        return True