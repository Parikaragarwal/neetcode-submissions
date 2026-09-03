class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        eltoid = {}

        for i in range(0,len(nums)):
            eltoid[nums[i]]=i
        
        for i in range(0,len(nums)):
            if target-nums[i] in eltoid and eltoid[target-nums[i]]!=i:
                return [i,eltoid[target-nums[i]]]
        return [-1,-1]