class FreqStack:

    def __init__(self):
        self.feq = {}
        self.id = 0
        self.pq = []

    def push(self, val: int) -> None:
        if val not in self.feq:
            self.feq[val]=1
        else:
            self.feq[val]+=1
        heapq.heappush(self.pq,(-self.feq[val],-self.id,val))
        self.id+=1
        

    def pop(self) -> int:
        a,b,c = heapq.heappop(self.pq)
        a=a*-1
        b=b*-1
        if c in self.feq:
           self.feq[c]-=1
           if self.feq[c]==0:
               self.feq.pop(c,None)
        return c
        


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()