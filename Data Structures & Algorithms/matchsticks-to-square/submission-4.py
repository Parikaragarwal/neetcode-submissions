class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        total: int = sum(matchsticks)
        maxside:int = max(matchsticks)
        if total % 4 != 0 or maxside>total//4:
            return False

        matchsticks.sort(reverse=True)
        side: int = total // 4
        parts: List[List[int]] = [[] for _ in range(4)]
        partsum: List[int] = [0, 0, 0, 0]

        def part(id: int):
            if id == len(matchsticks):
                return True
            stick: int = matchsticks[id]

            for i in range(0, 4):
                if partsum[i] == side:
                    continue
                if partsum[i] + stick <= side:
                    partsum[i] += stick
                    parts[i].append(stick)

                    success = part(id+1)
                    if success:
                        return True
                    
                    partsum[i] -= stick
                    parts[i].pop()
                else:
                    return False

            return False

        return part(0)
