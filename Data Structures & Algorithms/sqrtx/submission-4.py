class Solution:
    def mySqrt(self, x: int) -> int:
        if x<2:
            return x

        # start:int = 2
        # end:int = 47343

        # while start<=end:
        #     mid = start+(end-start)//2
        #     if mid*mid == x:
        #         return mid
        #     elif mid*mid < x:
        #         start=mid+1
        #     else:
        #         end=mid-1
            
        # return end

        est:float = x/2

        while True:
            newest:float = est - (est/2-x/(2*est))
            if int(newest)== int(est):
                return int(newest)
            est = newest

            