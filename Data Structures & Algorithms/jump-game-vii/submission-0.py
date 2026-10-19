class Queue:
    def __init__(self):
        self.dq = deque()

    def push(self, val):
        self.dq.append(val)

    def pop(self):
        return self.dq.popleft()

    def front(self):
        return self.dq[0]

    def empty(self):
        return len(self.dq) == 0

    def size(self):
        return len(self.dq)


class Solution:
    def canReach(self, st: str, minJ: int, maxJ: int) -> bool:
        q = Queue()

        farthest: int = 0
        n: int = len(st)
        end: int = n - 1

        if st[end] == "1":
            return False
        q.push(0)

        while not q.empty():
            id = q.pop()
            if id == end:
                return True
            s = max(farthest, id + minJ)
            e = min(end, id + maxJ)
            if s>end:
                continue

            for child in range(s, e + 1):
                if st[child] == "0":
                    q.push(child)
                    farthest = max(farthest, child)
        return False
