class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        rooms = [i for i in range(n)]
        occ = [] # min heap of (endtime,room)
        count = [0]*n
        heapq.heapify(rooms)

        for s,e in meetings:
            while occ and occ[0][0]<=s:
                end_time,room = heapq.heappop(occ)
                heapq.heappush(rooms,room)
            if rooms:
                room = heapq.heappop(rooms)
                actual_end = e
            else:
                end_time,room = heapq.heappop(occ)
                actual_end = end_time + (e-s)
            
            heapq.heappush(occ,(actual_end,room))
            count[room]+=1

        return count.index(max(count))
