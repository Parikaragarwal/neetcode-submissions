class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        ans: int = 0

        projects: List[List[int]] = []
        for i in range(0, len(capital)):
            projects.append([capital[i], profits[i]])

        projects.sort(key=lambda x: x[0])

        curr: int = 0

        pq = []
        while k:
            while curr<len(projects) and projects[curr][0] <= w:
                heapq.heappush(pq, (projects[curr][1] * -1, projects[curr][0]))
                curr += 1
            
            if not pq:
                return w
            
            [p,cap] = heapq.heappop(pq)
            p=p*-1

            w+=p
            ans+=p
            k-=1
        return w
