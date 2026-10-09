class DSU:
    def __init__(self,n:int):
        self.parents = [i for i in range(n)]
        self.rank = [0]*n
    
    def find(self,node:int) ->int:
        if self.parents[node]==node:
            return node
        
        self.parents[node] = self.find(self.parents[node])
        return self.parents[node]

    def union(self,a:int,b:int):
        a=self.find(a)
        b=self.find(b)
        if a==b:
            return

        if self.rank[a]<self.rank[b]:
            self.parents[a]=b
        elif self.rank[b]<self.rank[a]:
            self.parents[b]=a
        else:
            self.parents[a]=b
            self.rank[b]+=1

class Solution:
    def kruskal(self,n:int,pq,forceEdge=None):
        dsu = DSU(n)
        total:int = 0
        edgecount:int = 0
        if forceEdge is not None:
            a,b,w = forceEdge
            dsu.union(a,b)
            total+=w
            edgecount+=1

        while edgecount!=n-1 and pq:
            w,a,b = heapq.heappop(pq)
            if dsu.find(a)!=dsu.find(b):
                total+=w
                dsu.union(a,b)
                edgecount+=1
        if edgecount!=n-1:
            return -1

        return total
    
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        
        bpq = []
        for a,b,w in edges:
            heapq.heappush(bpq,(w,a,b))
        trueMstSum = self.kruskal(n,bpq)

        critical = []
        pseudoCritical = []

        for i in range(0,len(edges)):
            pq1 = []
            pq2 = []
            for j in range(0,len(edges)):
                if i==j:
                    continue
                a,b,w = edges[j]
                heapq.heappush(pq1,(w,a,b))
                heapq.heappush(pq2,(w,a,b))

            criticalCheck       = self.kruskal(n,pq1) !=  trueMstSum
            pseduoCriticalCheck = self.kruskal(n,pq2,edges[i]) == trueMstSum

            if criticalCheck:
                critical.append(i)
                continue
            if pseduoCriticalCheck:
                pseudoCritical.append(i)

        return [critical,pseudoCritical]






        