class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()

        rooms = [i for i in range(n)]
        meetcount = [0]*n
        occ = []

        heapq.heapify(rooms)
        # occ = heap -> push (end_time,room_no) [no negative as we need min heap]

        end_time = 0

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
            meetcount[room]+=1
            
        return meetcount.index(max(meetcount))
            
               
            

