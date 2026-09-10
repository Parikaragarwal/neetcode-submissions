class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        def binsearch(start: int, end: int) -> bool:
            while start <= end:
                mid: int = start + (end - start) // 2
                if nums[mid] == target:
                    return True
                elif nums[mid] < target:
                    start = mid + 1
                else:
                    end = mid - 1
            return False

        n: int = len(nums)
        start: int = 0
        end: int = n - 1
        while start <= end:
            if nums[start]==target or nums[end]==target:
                return True
            
            if nums[start] < nums[end]:
                return binsearch(start, end)

            mid: int = start + (end - start) // 2

            if nums[start] < nums[mid]:
                if target >= nums[start] and target <= nums[mid]:
                    return binsearch(start, mid)
                else:
                    start = mid + 1
            elif nums[mid]<nums[end]:
                if target >= nums[mid] and target <= nums[end]:
                    return binsearch(mid, end)
                else:
                    end = mid - 1
            else:
                start+=1
                end-=1

            
        return False






