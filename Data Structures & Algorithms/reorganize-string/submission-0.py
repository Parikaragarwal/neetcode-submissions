class Solution:
    def reorganizeString(self, s: str) -> str:
        pq = []
        feq = {}

        for ch in s:
            if ch not in feq:
                feq[ch] = 1
            else:
                feq[ch] += 1
        for key, value in feq.items():
            heapq.heappush(pq, (-value, key))

        ans = []

        prev = None
        while len(pq) > 0:
            value, key = heapq.heappop(pq)

            ans.append(key)
            feq[key] -= 1
            if feq[key] == 0:
                del feq[key]

            if prev and prev in feq:
                heapq.heappush(pq, (-feq[prev], prev))

            if key in feq:
                prev = key
            else:
                prev = None

        if len(ans) < len(s):
            return ""
        return "".join(ans)
