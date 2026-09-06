class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        seen = set()

        for el in nums[0:]:
            seen.add(el)
        
        ans:int = float('inf')
        
        for el in nums[0:]:
            if el+1 not in seen and el+1>0:
                ans = min(ans,el+1)
        
        if ans>1 and 1 not in seen:
            return 1
        return ans
        