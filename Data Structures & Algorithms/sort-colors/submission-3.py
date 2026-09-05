class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        mid:int = 0
        start:int = 0
        end:int = len(nums)-1

        while mid<=end:
            if nums[mid]==0:
                nums[mid],nums[start]=nums[start],nums[mid]
                start+=1
            elif nums[mid]==2:
                nums[mid],nums[end]=nums[end],nums[mid]
                end-=1
                mid-=1
            mid+=1
            
        

        