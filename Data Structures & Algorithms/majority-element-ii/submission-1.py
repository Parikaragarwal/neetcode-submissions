class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        a:int = -1
        b:int = -1
        ac:int = 0
        bc:int = 0

        for el in nums:
            if el==a and ac > 0:
                ac+=1
            elif ac == 0:
                a=el
                ac+=1
            elif el == b and bc > 0:
                bc+=1
            elif bc == 0:
                b = el
                bc+=1
            else:
                ac-=1
                bc-=1
            
        ac = 0
        bc = 0
        for el in nums:
            if el == a:
                ac+=1
            elif el==b:
                bc+=1
        
        ans=[]
        criteria:int = len(nums) // 3
        if ac > criteria:
            ans.append(a)
        if bc > criteria:
            ans.append(b)
        
        return ans




