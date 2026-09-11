class Solution:
    def findInMountainArray(self, target: int, mountainArr: 'MountainArray') -> int:
        def ascBinSearch(start:int,end:int)->int:
            ans:int = end+1
            lim:int = end
            while start<=end:
                mid:int = start+(end-start)//2
                el:int = mountainArr.get(mid)
                if el==target:
                    ans= min(ans,mid)
                    end=mid-1
                elif el>target:
                    end=mid-1
                else:
                    start=mid+1
            if ans > lim:
                return -1
            return ans
        def dscBinSearch(start:int,end:int)->int:
            ans:int = end+1
            lim:int = end
            while start<=end:
                mid:int = start+(end-start)//2
                el:int = mountainArr.get(mid)
                if el == target:
                    ans = min(ans,mid)
                    end = mid-1
                elif el>target:
                    start=mid+1
                else:
                    end = mid-1
            if ans > lim:
                return -1
            return ans

        def arr(id:int) ->int:
            if id<0:
                return float("-inf")
            if id>n-1:
                return float("inf")
            return mountainArr.get(id)
        
        n:int = mountainArr.length()
        start:int = 0
        end:int = n-1
        peak:int
        while start<=end:
            mid:int = start+(end-start)//2

            mel:int = arr(mid)
            l:int = arr(mid-1)
            r:int = arr(mid+1)

            if l<mel and mel>r:
                peak = mid
                break
            elif l<mel and mel<r:
                start=mid+1
            else:
                end=mid-1
        
        lid:int = ascBinSearch(0,peak)
        if lid!=-1:
            return lid
        
        rid:int = dscBinSearch(peak+1,n-1)
        if rid!=-1:
            return rid

        return -1

