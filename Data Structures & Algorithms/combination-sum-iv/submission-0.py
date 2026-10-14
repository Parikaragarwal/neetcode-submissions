class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        n:int = len(nums)
        dp = [-1 for _ in range(target+1)]

        def comb(sum) ->int:
            if sum==target:
                return 1
            if sum>target:
                return 0
            
            if dp[sum]!=-1:
                return dp[sum]
            
            ans:int = 0
            for el in nums:
                ans+= comb(sum+el)
            dp[sum]=ans
            return ans

        return comb(0)

            