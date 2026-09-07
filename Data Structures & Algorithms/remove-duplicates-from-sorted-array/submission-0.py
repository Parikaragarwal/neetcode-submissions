class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        curr:int = 1
        trav:int = nums[0]

        for el in nums:
            if trav!=el:
                nums[curr]=el
                curr+=1
                trav = el
        return curr