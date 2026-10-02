class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total:int = sum(nums)
        maxel:int = max(nums)

        nums.sort(reverse=True)

        if total%k!=0 or maxel>total//k:
            return False

        subsum:int = total//k
        parts = [[] for _ in range(k)]
        partsum = [0 for _ in range(k)]

        def partition(id:int):
            if id == len(nums):
                return True
            
            el:int = nums[id]
            visited = set()
            for i in range(0,k):
                if partsum[i] in visited:
                    continue
                
                if partsum[i] + el <= subsum:
                    partsum[i]+= el
                    parts[i].append(el)

                    if partition(id+1):
                        return True

                    partsum[i]-=el
                    parts[i].pop()
                    visited.add(partsum[i])
            return False

        return partition(0)