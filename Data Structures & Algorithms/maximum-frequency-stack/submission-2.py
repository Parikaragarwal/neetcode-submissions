class FreqStack:
    def __init__(self):
        self.feq = {}
        self.maxfeq = 0
        self.store: List[List[int]] = [[]]

    def push(self, val: int) -> None:
        if val not in self.feq:
            self.feq[val] = 1
        else:
            self.feq[val] += 1
        self.maxfeq = max(self.maxfeq, self.feq[val])
        if self.feq[val] == len(self.store):
            self.store.append([val])
        else:
            self.store[self.feq[val]].append(val)

    def pop(self) -> int:
        el: int = self.store[-1].pop()
        self.feq[el]-=1
        if self.feq[el]==0:
            self.feq.pop(el,None)
        if not self.store[-1]:
            self.store.pop()
            self.maxfeq -= 1
        return el


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
