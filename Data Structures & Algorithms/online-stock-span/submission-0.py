class StockSpanner:

    def __init__(self):
        self.record = []
        

    def next(self, price: int) -> int:
        self.record.append(price)
        size:int = len(self.record)

        end:int = size - 1
        curr = end-1
        while curr>=0 and self.record[curr]<=price:
            curr-=1
        return end-curr
        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)