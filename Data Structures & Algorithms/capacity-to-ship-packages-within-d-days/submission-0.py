class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def daysForWeight(cap:int) -> int:
            dn:int = 0
            ship:int = 0

            for w in weights:
                if ship+w <= cap:
                    ship+=w
                else:
                    ship = w
                    dn+=1
                    if ship>cap:
                        return -1
            if ship<=cap:
                return dn+1
            else:
                return -1

        start:int = max(weights)
        end:int = sum(weights)
        ans:int = end
        while start<=end:
            mid:int = start+(end-start)//2
            dn:int = daysForWeight(mid)

            if dn<=days:
                ans = mid
                end=mid-1
            else:
                start=mid+1
        return ans
