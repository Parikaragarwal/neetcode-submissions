class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # seen = set()

        # for el in nums[0:]:
        #     seen.add(el)
        
        # ans:int = float('inf')
        
        # for el in nums[0:]:
        #     if el+1 not in seen and el+1>0:
        #         ans = min(ans,el+1)
        
        # if ans>1 and 1 not in seen:
        #     return 1
        # return ans
        n:int = len(nums)
        for i in range(0,n):
            el:int = nums[i]
           
            while(i!=i+1 and el<=n and el>=1 and nums[el-1]!=el):
                nums[el-1],nums[i] = nums[i],nums[el-1]
                el= nums[i]
            
        for i in range(0,n):
            if nums[i]!=i+1:
                return i+1
        return n+1