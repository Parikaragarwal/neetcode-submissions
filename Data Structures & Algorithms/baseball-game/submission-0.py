class Solution:
    def calPoints(self, operations: List[str]) -> int:
        score:List[int] = []

        for el in operations:
            if el == "+":
                score.append(score[-1]+score[-2])
            elif el == "D":
                score.append(score[-1]*2)
            elif el == "C":
                score.pop()
            else:
                score.append(int(el))
        
        return sum(score)