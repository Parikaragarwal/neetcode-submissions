class Solution:
    def comb(self,n: int, k:int , ans : List[List[int]] , curr: List[int] , start:int) ->List[List[int]]:
        if k == 0:
            ans.append(curr.copy())
            return
        if start == n+1:
            return
        
        for i in range(start,n-k+2):
            curr.append(i)
            self.comb(n,k-1,ans,curr,i+1)
            curr.pop()
            



    def combine(self, n: int, k: int) -> List[List[int]]:
        ans:List[List[int]] = []
        curr:List[int] = []
        self.comb(n,k,ans,curr,1)
        return ans