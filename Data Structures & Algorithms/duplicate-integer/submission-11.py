class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # nums.sort()

        # for i in range(0,len(nums)-1):
        #     if nums[i]==nums[i+1]:
        #         return True
        
        # return False
        seen = set()

        for i in range(0,len(nums)):
            if nums[i] in seen:
                return True
            seen.add(nums[i])
        return False