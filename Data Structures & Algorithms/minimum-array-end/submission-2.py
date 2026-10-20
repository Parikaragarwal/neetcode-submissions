class Solution:
    def minEnd(self, n: int, x: int) -> int:
        def tobin(el):
            ans = []
            for i in range(64):
                ans.append(1 & (el>>i))
            return ans
        def revmsb(arr):
            for i in range(63,-1,-1):
                if arr[i]==1:
                    return i
        def todec(arr):
            ans = 0
            for i in range(64):
                ans+= (2**i)*arr[i]
            return ans
        
        if n==1:
            return x
        xbin = tobin(x)
        nbin = tobin(n-1)
        

        msbid = revmsb(nbin)

        i:int = 0
        j:int = 0

        while i<=msbid:
            while xbin[j]==1:
                j+=1
            xbin[j] = nbin[i]
            i+=1
            j+=1
        
        return todec(xbin)
        
            

        
