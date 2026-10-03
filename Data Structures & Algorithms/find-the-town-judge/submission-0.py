class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        people_who_trust_me:List[int] = [0 for _ in range(n)]
        people_who_i_trust:List[int] = [0 for _ in range(n)]

        for i in range(len(trust)):
            truster = trust[i][0]
            trusterid = truster - 1
            trusted = trust[i][1]
            trustedid = trusted - 1

            people_who_trust_me[trustedid]+=1
            people_who_i_trust[trusterid]+=1

        for i in range(n):
            if people_who_trust_me[i]==n-1 and people_who_i_trust[i]==0:
                return i+1
            
        
        return -1