class Solution:
    def validPalindrome(self, s: str) -> bool:

        def isPalindrome(l:int,r:int):
            while l<=r:
                if s[l]!=s[r]:
                    return False
                l+=1
                r-=1
            return True

        start:int = 0
        end: int = len(s)-1
        deleted:bool = False

        while start<=end:
            if start<=end:
                if s[start]==s[end]:
                    start+=1
                    end-=1
                    continue
                else:
                    return isPalindrome(start+1,end) or isPalindrome(start,end-1)

        return True
            
            
        