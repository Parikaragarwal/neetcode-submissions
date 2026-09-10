class Solution:
    def mySqrt(self, x: int) -> int:
        if x<2:
            return x

        start:int = 2
        end:int = 47341

        while start<=end:
            mid = start+(end-start)//2
            if mid*mid == x:
                return mid
            elif mid*mid < x:
                start=mid+1
            else:
                end=mid-1
            
        return end
            