class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        pq = []
        ans: List[str] = []

        if a > 0:
            heapq.heappush(pq, (-a, "a"))
        if b > 0:
            heapq.heappush(pq, (-b, "b"))
        if c > 0:
            heapq.heappush(pq, (-c, "c"))

        while pq:
            val, ch = heapq.heappop(pq)
            val = val * -1
            
            if len(ans)>1 and ans[-1] == ans[-2] == ch:
                if not pq:
                    return "".join(ans)
                else:
                    nextval, nextch = heapq.heappop(pq)
                    nextval = nextval * -1
                    ans.append(nextch)
                    nextval -= 1
                    if nextval > 0:
                        heapq.heappush(pq, (-nextval, nextch))
                    heapq.heappush(pq,(-val,ch))
            else:
                ans.append(ch)
                val -= 1
                if val > 0:
                    heapq.heappush(pq, (-val, ch))

        return "".join(ans)
