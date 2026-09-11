class Solution:
    def splitArray(self, nums: List[int], k: int) -> List[int]:
        def partisan(cap:int) ->List[int]:
            mxsum:int = 0;
            sub:int = 0
            blocks:int = 0

            for el in nums:
                if el+sub<=cap:
                    sub+=el
                else:
                    mxsum = max(mxsum,sub)
                    sub = el
                    blocks+=1
            
            if sub>0:
                mxsum = max(mxsum,sub)
                blocks+=1
            return [blocks,mxsum]

        start:int = max(nums)
        end:int = sum(nums)

        ans:int = end
        while start<=end:
            mid:int = start+(end-start)//2
            p,mxsum = partisan(mid)

            if p<=k:
                ans = min(ans,mxsum)
                end = mxsum-1
            else:
                start=mid+1
                
        return ans

        