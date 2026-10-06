class DSU:
    def __init__(self, size: int):
        self.parent = [i for i in range(size)]
        self.rank = [0] * size

    def find(self, val: int) -> int:
        if self.parent[val] == val:
            return val
        self.parent[val] = self.find(self.parent[val])
        return self.parent[val]

    def union(self, a: int, b: int):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return

        if self.rank[a] < self.rank[b]:
            self.parent[a] = b
        elif self.rank[b] < self.rank[a]:
            self.parent[b] = a
        else:
            self.parent[a] = b
            self.rank[a] += 1

    def parents(self):
        els: List[int] = []
        for i in range(0, len(self.parent)):
            if i == self.parent[i]:
                els.append(i)
        return els


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        dsu = DSU(len(accounts))
        mailuser = {}

        for i, account in enumerate(accounts):
            for mail in account[1:]:
                if mail in mailuser:
                    dsu.union(i, mailuser[mail])
                else:
                    mailuser[mail] = i

        ans: List[List[str]] = []
        parents = dsu.parents()

        id = {}
        for i, el in enumerate(parents):
            ans.append([accounts[el][0]])
            id[el] = i

        for key, value in mailuser.items():
            ans[id[dsu.find(value)]].append(key)

        for account in ans:
            account[1:] = sorted(account[1:])   

        return ans
