class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        occured = {}

        for i in range(0,len(nums)):
            el:int = nums[i]
            if el not in occured:
                occured[el] = i
            else:
                if i-occured[el]<=k:
                    return True
                else:
                    occured[el] = i
        return False