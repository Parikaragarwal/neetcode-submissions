class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        board = {}
        exit = {}

        start = trips[0][1]
        end = trips[0][2]

        for trip in trips:
            passangers = trip[0]
            pickup = trip[1]
            destination = trip[2]
            start = min(start, pickup)
            end = max(end, destination)

            if pickup in board:
                board[pickup] += passangers
            else:
                board[pickup] = passangers
            if destination in exit:
                exit[destination] += passangers
            else:
                exit[destination] = passangers

        curr: int = 0
        for i in range(start, end + 1):
            if i in board:
                curr += board[i]
            if i in exit:
                curr -= exit[i]

            if curr > capacity:
                return False
        return True
