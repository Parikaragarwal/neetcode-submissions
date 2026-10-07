class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        
        ROWS,COLS = len(heights),len(heights[0])
        directions:List[List[int]] = [[-1,0],[1,0],[0,-1],[0,1]]

        pq = []
        heapq.heappush(pq,(0,0,0))
        visited = set()

        while pq:
            diff,i,j = heapq.heappop(pq)
            
            if (i,j) in visited:
                continue

            if (i,j) == (ROWS-1,COLS-1):
                return diff

            visited.add((i,j))

            for di,dj in directions:
                ni = i+di
                nj = j+dj

                if ni>=0 and nj>=0 and ni<ROWS and nj<COLS and (ni,nj) not in visited:
                    newdiff = max(diff,abs(heights[i][j]-heights[ni][nj]))
                    heapq.heappush(pq,(newdiff,ni,nj))
             
