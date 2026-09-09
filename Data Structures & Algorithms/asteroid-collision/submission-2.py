class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        ans:List[int] = []
        for ast in asteroids:
            while ans and ans[-1]>0 and ast<0 and ans[-1]<=abs(ast):
                if ans.pop()+ast==0:
                    ast=0
                    break
            if ans and ans[-1]>0 and ast<0 and ans[-1]>abs(ast):
                continue
            if ast!=0:
                ans.append(ast)
        return ans

                    
                
                

