class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        total:int = 0
        l:int = 0
        r:int = 0

        n:int = len(nums)
        ans:int = n


        for el in nums:
            total+=el
        if total<target:
            return 0
        
        total = 0
        while r<n:
            while r<n and total<target:
                total+=nums[r]
                if total>=target:
                    break
                r+=1
            
            while l<=r and total>=target:
                ans = min(ans,r-l+1)
                total-= nums[l]
                l+=1
            r+=1
            
        return ans
        