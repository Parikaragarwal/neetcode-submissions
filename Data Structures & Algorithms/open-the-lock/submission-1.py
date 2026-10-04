class Queue:
    def __init__(self):
        self.dq = deque()

    def push(self, el):
        self.dq.append(el)

    def pop(self):
        return self.dq.popleft()

    def size(self) -> int:
        return len(self.dq)

    def front(self):
        return self.dq[0]

    def empty(self) -> bool:
        return len(self.dq) == 0


class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)
        visited = set()

        q: Queue = Queue()
        q.push("0000")
        moves:int = 0

        while not q.empty():

            n:int = q.size()

            for _ in range(n):
                curr = q.pop()
                if curr in visited:
                    continue
                visited.add(curr)

                if curr == target:
                    return moves

                if curr in deadends:
                    continue

                
                for i in range(4):
                    digit: int = int(curr[i])

                    digl = (digit + 1) % 10
                    digr = (digit + 9) % 10

                    childl: str = curr[:i] + str(digl) + curr[i + 1 :]
                    childr: str = curr[:i] + str(digr) + curr[i + 1 :]
                    
                    if childr not in visited:
                        q.push(childr)
                    if childl not in visited:
                        q.push(childl)
            
            moves+=1
                
        return -1
