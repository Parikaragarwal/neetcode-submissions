class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        adj = defaultdict(set)

        if n==1:
            return [0]
        if n==2:
            return [0,1]

        for a,b in edges:
            adj[a].add(b)
            adj[b].add(a)

        edge_count = {}
        leaves:List[int] = []

        for node,children in adj.items():
            edge_count[node] = len(children)
            if len(children) == 1:
                leaves.append(node)

        while leaves:
            if len(edge_count)<=2:
                return leaves

            nextgen:List = []

            for leaf in leaves:
                leafchild = adj[leaf].pop()
                del(adj[leaf])
                del(edge_count[leaf])

                edge_count[leafchild]-=1
                adj[leafchild].remove(leaf)
                
                if edge_count[leafchild]==1:
                    nextgen.append(leafchild)
            
            leaves = nextgen
        
        return [0]

















