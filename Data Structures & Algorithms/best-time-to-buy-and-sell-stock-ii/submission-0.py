class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        INF = float('inf')
        bought:int = INF
        profit:int = 0
        for i in range(0,len(prices)):
            if prices[i]>bought:
                profit+= prices[i]-bought

            bought = prices[i]
        return profit 
            