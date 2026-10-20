class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        if left&right==0:
            return 0

        def msbloc(arr):
            for i in range(32):
                if arr[i]==1:
                    return i
        def tobin(el):
            ans:List[int] = []
            for i in range(32):
                ans.append( 1 & (el>>i))
            ans.reverse()
            return ans
        def todec(arr):
            ans:int = 0
            for i in range(32):
                ans+= (2**(31-i))*arr[i]
            return ans

        lbin = tobin(left)
        rbin = tobin(right)

        if msbloc(lbin)!=msbloc(rbin):
            return 0
        
        i:int = 0
        msbe = False

        while i<32:
            if msbe:
                lbin[i]=0
                rbin[i]=0
                i+=1
                continue
            
            if lbin[i]==0 and rbin[i]==0:
                i+=1
                continue
            
            while i<32 and lbin[i]==rbin[i]:
                i+=1
            if i==32:
                break
            msbe= True
            
            lbin[i]=0
            rbin[i]=0
            i+=1

        return todec(lbin)
        
            