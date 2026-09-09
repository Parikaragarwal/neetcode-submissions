class StockSpanner:

    def __init__(self):
        self.record:List[List[int]] = []
        

    def next(self, price: int) -> int:
        el:List[int] = [price,1]
        while self.record and self.record[-1][0]<=price:
            el[1]+=self.record[-1][1]
            self.record.pop()
        self.record.append(el)
        return el[1]
        
        # self.record.append(price)
        # size:int = len(self.record)

        # end:int = size - 1
        # curr = end-1
        # while curr>=0 and self.record[curr]<=price:
        #     curr-=1
        # return end-curr
        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)