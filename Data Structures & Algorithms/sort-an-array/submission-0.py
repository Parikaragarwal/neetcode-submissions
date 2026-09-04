class Solution:
    def quicksort(self,nums:List[int],start:int,end:int) -> None:
        pivotindex:int = (start+end)//2
        if(start>=end):
            return
        
        ogstart:int = start
        ogend: int = end

        pivot:int = nums[pivotindex]

        nums[start],nums[pivotindex] = nums[pivotindex],nums[start]
        
        start+=1
        while start<=end:
            
            while nums[start]<=pivot and start<ogend:
                start+=1
            while nums[end]>=pivot and end>ogstart:
                end-=1
            if(start<end):
                nums[start],nums[end] = nums[end],nums[start]
            else:
                break
            start+=1
            end-=1
        
        nums[end],nums[ogstart] = nums[ogstart],nums[end]
        self.quicksort(nums,ogstart,end-1)
        self.quicksort(nums,end+1,ogend)

            
    def sortArray(self, nums: List[int]) -> List[int]:
        self.quicksort(nums,0,len(nums)-1)
        return nums