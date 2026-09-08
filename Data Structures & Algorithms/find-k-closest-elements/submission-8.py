class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        ans:List[int] = []
        n:int = len(arr)

        l:int=0
        r:int = n-1

        if x<arr[0]:
            return arr[0:k]
        if x>arr[n-1]:
            return arr[n-k:n]
            
        while l<=r:
            mid:int = (r+l) // 2
            if arr[mid]==x:
                l=mid
                r=mid+1
                break
            elif arr[mid]<x:
                l=mid+1
            else:
                r=mid-1
        if l>=0 and arr[l]!=x:
          [r,l] = [l,r]

        dq = deque()

        while len(dq)<k and l>=0 and r<n:
            if abs(arr[l]-x) <= abs(arr[r]-x):
                dq.appendleft(arr[l])
                l-=1
            else:
                dq.append(arr[r])
                r+=1
        
        while l<0 and len(dq)<k and r<n:
            dq.append(arr[r])
            r+=1
        while r>=n and len(dq)<k and l>=0:
            dq.appendleft(arr[l])
            l-=1
        
        return list(dq)








        