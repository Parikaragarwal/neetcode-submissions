class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        comps = []
        n:int = len(arr)
        if n==1:
            return 1

        for i in range(0,n-1):
            if arr[i]<arr[i+1]:
                comps.append(-1)
            elif arr[i]==arr[i+1]:
                comps.append(0)
            else:
                comps.append(1)
        res:int = 0
        currlen=0

        for i in range(len(comps)):
            if comps[i]==0:
                currlen=0
            elif i>=0 and comps[i-1]==comps[i]:
                currlen=1
            else:
                currlen+=1
            res = max(res,currlen)
        return res+1