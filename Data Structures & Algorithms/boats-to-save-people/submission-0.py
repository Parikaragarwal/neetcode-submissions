class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        left:int = 0
        right:int = len(people)-1
        people.sort()
        ans = 0
        while left<=right:
            if people[left]+people[right]<=limit:
                left+=1
                right-=1
            else:
                right-=1

            ans+=1
        return ans
