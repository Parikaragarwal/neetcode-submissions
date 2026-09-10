class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        start:int = 0
        end:int = len(nums)-1

        while start<=end:
            mid:int = start+(end-start)//2
            if nums[mid]==target:
                return mid
            elif nums[mid]<target:
                start=mid+1
            else:
                end=end-1
            
        return start