class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i:int = 0
        j:int = 0
        n:int = len(nums)

        
        
        while j<n:
            if nums[j]!=val:
                nums[i],nums[j]=nums[j],nums[i]
                i+=1
            j+=1
        return i