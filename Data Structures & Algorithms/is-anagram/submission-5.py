class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
      sels = {}
      tels = {}

      for i in range(0,len(s)):
        if s[i] in sels:
            sels[s[i]]=sels[s[i]]+1
        else:
            sels[s[i]]=1

      for i in range(0,len(t)):
        if t[i] in tels:
            tels[t[i]]=tels[t[i]]+1
        else:
            tels[t[i]]=1
    
      for key,vals in tels.items():
        if key not in sels:
            return False

            
      for key,vals in sels.items():
        if key not in tels or vals != tels[key]:
            return False
    
      return True
