class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count:int = 1
        val:int = nums[0]
        for i in range(1,len(nums)):
            if nums[i]==val:
                count+=1
            else:
                count-=1
            
            if count==0:
                val=nums[i]
                count=1

        return val
            
            