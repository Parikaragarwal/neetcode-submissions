class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixcount = {}

        prefixcount[0]=1
        sum:int = 0
        ans:int = 0
        for i in nums[0:]:
            sum+=i
            if sum-k in prefixcount:
                ans+=prefixcount[sum-k]
            
            if sum in prefixcount:
                prefixcount[sum]+=1
            else:
                prefixcount[sum]=1
        
        return ans