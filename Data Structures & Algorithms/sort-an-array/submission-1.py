from random import randint
class Solution:
    def quicksort(self,nums:List[int],start:int,end:int) -> None:
        
        if(start>=end):
            return
        pivotindex:int = randint(start,end)
        pivot:int = nums[pivotindex]

        ogstart:int = start
        ogend: int = end

        mid:int = start
        while mid<=end:
            if nums[mid]<pivot:
                nums[mid],nums[start] = nums[start],nums[mid]
                start+=1
            elif nums[mid]>pivot:
                nums[mid],nums[end] = nums[end],nums[mid]
                end-=1
                mid-=1
            mid+=1
        
        self.quicksort(nums,ogstart,start-1)
        self.quicksort(nums,end+1,ogend)

            
    def sortArray(self, nums: List[int]) -> List[int]:
        self.quicksort(nums,0,len(nums)-1)
        return nums