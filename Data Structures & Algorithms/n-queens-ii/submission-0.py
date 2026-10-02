class Solution:
    def totalNQueens(self, n: int) -> int:

        dscdg: List[bool] = [False for _ in range(2 * n + 1)]
        ascdg: List[bool] = [False for _ in range(2 * n + 1)]
        row: List[bool] = [False for _ in range(n)]

        ans: int = 0

        def placequeen(j: int):
            nonlocal ans
            if j == n:
                ans = ans + 1
                return

            for i in range(n):
                dscdgid: int = i + j
                ascdgid: int = i - j + n - 1
                rowid = i

                if dscdg[dscdgid] or ascdg[ascdgid] or row[rowid]:
                    continue

                dscdg[dscdgid] = True
                ascdg[ascdgid] = True
                row[rowid] = True

                placequeen(j + 1)

                dscdg[dscdgid] = False
                ascdg[ascdgid] = False
                row[rowid] = False

        placequeen(0)

        return ans
