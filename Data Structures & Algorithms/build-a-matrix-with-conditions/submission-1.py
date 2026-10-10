class Queue:
    def __init__(self):
        self.dq = deque()
    def push(self,el):
        self.dq.append(el)
    def pop(self):
        return self.dq.popleft()
    def front(self):
        return self.dq[0]
    def size(self):
        return len(self.dq)
    def empty(self):
        return len(self.dq)==0
    
class Solution:

    def topsort(self,adj,indeg):
        q = Queue()
        ans = []

        for i in range(1,len(indeg)):
            if indeg[i]==0:
                q.push(i)

        while not q.empty():
            el = q.pop()
            ans.append(el)

            for child in adj[el]:
                indeg[child]-=1
                if indeg[child]==0:
                    q.push(child)
        
        return ans
                


    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:

        adjr = [[] for i in range(0,k+1)]
        adjc = [[] for i in range(0,k+1)]

        indegr = [0]*(k+1)
        indegc = [0]*(k+1)

        for a,b in rowConditions:
            adjr[a].append(b)
            indegr[b]+=1
        for a,b in colConditions:
            adjc[a].append(b)
            indegc[b]+=1

        rowels = self.topsort(adjr,indegr)
        colels = self.topsort(adjc,indegc)

        if len(rowels)!=k or len(colels)!=k:
            return []
        
        ans = [[0]*k for _ in range(k) ]
        pos = defaultdict(list)
        for i in range(0,len(rowels)):
            el = rowels[i]
            pos[el].append(i)
        for i in range(0,len(colels)):
            el = colels[i]
            pos[el].append(i)
        
        for key,val in pos.items():
            ans[val[0]][val[1]] = key

        return ans
        

        