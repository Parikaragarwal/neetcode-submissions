class MyStack:

    def __init__(self):
        self.q = deque()
        self.aq = deque()
    
    def push(self, x: int) -> None:
        self.aq.append(x)
        while len(self.q)>0:
            self.aq.append(self.q[0])
            self.q.popleft()
        

        while len(self.aq)>0:
            self.q.append(self.aq[0])
            self.aq.popleft()
        

    def pop(self) -> int:
        return self.q.popleft()
        

    def top(self) -> int:
        return self.q[0]
        

    def empty(self) -> bool:
        return len(self.q)==0
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()