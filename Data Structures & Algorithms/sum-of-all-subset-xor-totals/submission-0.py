class Solution:
    def subset(self,currid,nums:List[int],currxor:int) ->int:
        if currid == len(nums):
            return currxor
        
        ans = self.subset(currid+1,nums,currxor) + self.subset(currid+1,nums,currxor^nums[currid])
        return ans
    
    def subsetXORSum(self, nums: List[int]) -> int:
        return self.subset(0,nums,0)