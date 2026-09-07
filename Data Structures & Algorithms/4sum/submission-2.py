class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        ans: List[List[int]] = []

        for i in range(0, len(nums)-3):
            if i > 0 and nums[i - 1] == nums[i]:
                continue
            for j in range(i+1, len(nums)-2):
                if j > i+1 and nums[j - 1] == nums[j]:
                    continue
                currtarget:int = target - (nums[i]+nums[j])
                start: int = j + 1
                end: int = len(nums) - 1

                while start < end:
                    sum: int = nums[start] + nums[end]
                    
                    if sum == currtarget:
                        ans.append([nums[i], nums[j], nums[start], nums[end]])
                        start += 1
                        end -= 1
                        while start<end and start>0 and nums[start]==nums[start-1]:
                            start+=1
                        while start<end and end<len(nums)-1 and nums[end]==nums[end+1]:
                            end-=1
                    elif sum < currtarget:
                        start += 1
                    else:
                        end -= 1
        return ans
