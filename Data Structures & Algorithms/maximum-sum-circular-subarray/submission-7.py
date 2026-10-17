class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        rs=0
        ans = nums[0]
        for el in nums:
            rs+=el
            if rs>=0:
                ans=max(ans,rs)
            else:
                ans=max(ans,el)
                rs=0
        if ans<0:
            return ans

        crs=0
        cans=-1*nums[0]

        for el in nums:
            el=el*-1
            crs+=el
            if crs>=0:
                cans=max(cans,crs)
            else:
                crs=0
        ans = max(ans,sum(nums)+cans)
            
        return ans
        

        