class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        for i in range(0,len(tasks)):
            tasks[i].append(i)
        
        tasks.sort(key=lambda x:x[0],reverse=True)
        nextRoundTime:int = 0
        ans:List[int] = []
        pq = []

        while tasks or pq:
            while tasks and tasks[-1][0]<=nextRoundTime:
                  heapq.heappush(pq,(tasks[-1][1],tasks[-1][2]))
                  tasks.pop()
            
            if pq:
               nextTask = heapq.heappop(pq)
               processingTime:int = nextTask[0]
               index:int = nextTask[1]

               ans.append(index)
               nextRoundTime+=processingTime
            else:
               nextTask = tasks.pop()
               nextRoundTime = nextTask[0]
               heapq.heappush(pq,(nextTask[1],nextTask[2]))
        
        return ans


