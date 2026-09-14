"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val=False, isLeaf=False, topLeft=None, topRight=None, bottomLeft=None, bottomRight=None):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def allLeaf(self,children:List[Node])->bool:
        for el in children:
            if not el.isLeaf:
                return False
        return True

    def allEqual(self,children:List[Node])->bool:
        val = children[0].val
        for el in children:
            if el.val!=val:
                return False
        return True

    def recurse(self,grid:List[List[int]],r:int,c:int,n):
        if n==1:
            return Node(bool(grid[r][c]==1),True,None,None,None,None)
        
        half:int = n//2
        tl = self.recurse(grid ,r       ,c     , half)
        tr = self.recurse(grid ,r       ,c+half, half)
        bl = self.recurse(grid ,r+half  ,c     , half)
        br = self.recurse(grid ,r+half  ,c+half, half)

        children:List[Node] = [tl,tr,bl,br]
        if self.allLeaf(children) and self.allEqual(children):
           return Node(tl.val,True,None,None,None,None)
        
        return Node(tl.val,False,tl,tr,bl,br)
           
    def construct(self, grid: List[List[int]]) -> 'Node':
        n:int = len(grid)
        return self.recurse(grid,0,0,n)
        
        