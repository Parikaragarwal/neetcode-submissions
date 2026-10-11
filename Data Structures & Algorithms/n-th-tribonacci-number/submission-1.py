class Solution:
    def tribonacci(self, n: int) -> int:
        trairs = [0,1,1]

        if n<=2:
            return trairs[n]

        for i in range(3,n+1):
            next:int = sum(trairs)
            trairs[0]=trairs[1]
            trairs[1]=trairs[2]
            trairs[2]=next

        return trairs[2]