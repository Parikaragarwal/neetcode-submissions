class MyCircularQueue:
    def __init__(self, k: int):
        self.n: int = k
        self.f: int = 0
        self.r: int = 0
        self.q: List[int] = [-1] * k

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        
        self.q[self.r] = value
        self.r = (self.r + 1) % self.n
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.q[self.f] = -1
        self.f = (self.f + 1) % self.n
        return True

    def Front(self) -> int:
        return self.q[self.f]

    def Rear(self) -> int:
        return self.q[(self.n+self.r-1)%self.n]

    def isEmpty(self) -> bool:
        if self.f == self.r and self.q[self.r] == -1:
            return True
        return False

    def isFull(self) -> bool:
        if self.r == self.f and self.q[self.r]!=-1:
            return True
        return False
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
