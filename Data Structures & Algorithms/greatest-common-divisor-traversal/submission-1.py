class DSU:
    def __init__(self,n:int):
        self.parents = [i for i in range(n)]
        self.rank = [0]*n
        self.components = n
    def find(self,el):
        if el==self.parents[el]:
            return el
        self.parents[el] = self.find(self.parents[el])
        return self.parents[el]
    def union(self,a,b):
        a = self.find(a)
        b = self.find(b)
        if a==b:
            return 

        if self.rank[a]<self.rank[b]:
            self.parents[a] = b
        elif self.rank[b]<self.rank[a]:
            self.parents[b] = a
        else:
            self.parents[a] = b
            self.rank[b]+=1
        self.components-=1
    def connected(self):
        return self.components==1


class Solution:

    def createSpf(self,maxel):
        spf = [i for i in range(0,maxel+1)]

        for i in range(2,maxel+1):
            if spf[i]!=i:
                continue
            for j in range(i,maxel+1,i):
                spf[j]=i
        return spf
    
    def primefactors(self,el,spf):
        ans = set()
        while el!=1:
            ans.add(spf[el])
            el = el//spf[el]
        
        return list(ans)

    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        
        maxel = max(nums)
        spf = self.createSpf(maxel)
        dsu = DSU(len(nums))

        primes = defaultdict(list)
        

        for i,el in enumerate(nums):
            factors = self.primefactors(el,spf)
            for f in factors:
                if primes[f]:
                    dsu.union(i,primes[f][0])
                primes[f].append(i)

        return dsu.connected()
        
