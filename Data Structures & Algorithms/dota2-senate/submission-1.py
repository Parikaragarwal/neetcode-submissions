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
    def predictPartyVictory(self, senate: str) -> str:
        q = Queue()
        r:int = 0
        d:int = 0
        sr:int = 0
        sd:int = 0
        
        for s in senate:
            if s=='R':
                r+=1
            elif s=='D':
                d+=1
            q.push(s)
        if r==0:
            return "Dire"
        if d==0:
            return "Radiant"
        while not q.empty():
            curr = q.pop()

            if curr=='R':
                if sr>0:
                    sr-=1
                    continue
                d-=1
                sd+=1

                if d==0:
                    return "Radiant"
            else:
                if sd>0:
                    sd-=1
                    continue
                r-=1
                sr+=1

                if r==0:
                    return "Dire"    
            q.push(curr)

        return "Dire"
       