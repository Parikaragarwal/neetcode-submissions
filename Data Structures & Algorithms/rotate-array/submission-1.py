class Solution:
    def gcd(self,a,b):
        if a==0:
            return b
        elif b == 0:
            return a
        if a > b:
            return self.gcd(a-b,b)
        else:
            return self.gcd(a,b-a)

    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n:int = len(nums)
        k = k%n
        
        #number of cycles
        C:int = self.gcd(n,k)
        #number of elements in each cycle
        N:int = n // C
        
        l:int = 0

        while l<C:
            curr:int = l
            el = nums[curr]
            for i in range(0,N):
                nextel:int = nums[(curr+k)%n]
                nums[(curr+k)%n]=el
                el = nextel
                curr = (curr+k)%n
            l+=1
        
        