class Queue:
    def __init__(self):
        self.dq = deque()

    def push(self,el):
        self.dq.append(el)

    def front(self):
        return self.dq[0]

    def pop(self):
        return self.dq.popleft()

    def size(self) -> int:
        return len(self.dq)

    def empty(self) -> bool:
        return len(self.dq) == 0

class Solution:
    def calcEquation(
        self, equations: List[List[str]], values: List[float], queries: List[List[str]]
    ) -> List[float]:

        children = {}

        for i in range(len(values)):
            a, b = equations[i]
            val = values[i]

            if not a in children:
                children[a] = []
            if not b in children:
                children[b] = []

            children[a].append([b, val])
            children[b].append([a, 1/val])

        def bfs(a,b) ->int:
            if a not in children or b not in children:
                return -1

            q:Queue = Queue()
            visited = set()
            q.push([a,1])

            while not q.empty():
                curr,val = q.pop()

                if curr == b:
                    return val

                if curr in visited:
                    continue
                
                visited.add(curr)

                kids = children[curr]
                for child,edge in kids:
                    if child not in visited:
                        q.push([child,val*edge])

            return -1

        ans = []

        for p,q in queries:
            cand1 = bfs(p,q)
            cand2 = bfs(q,p)
            if cand1!=-1:
                ans.append(cand1)
            elif cand2!=-1:
                ans.append(1/cand2)
            else:
                ans.append(-1)

        return ans








