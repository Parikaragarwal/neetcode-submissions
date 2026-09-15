# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.mp ={}
    def poss(self,root:Optional[TreeNode]) ->List[int]:
        if not root:
            return [0,0]
        withroot:int = root.val
        withoutroot:int = 0

        left = [0,0]
        right = [0,0]
        if root.left:
            left = self.poss(root.left)
        if root.right:
            right = self.poss(root.right)
        
        withroot+= left[1]+right[1]
        withoutroot += max(left)+max(right)

        return [withroot,withoutroot]
        
    def rob(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return max(self.poss(root))
        
        
        # if root in self.mp:
        #     return self.mp[root]
        
        # cand1:int = root.val
        # cand2:int = 0
        # if root.left:
        #     cand1+=self.rob(root.left.left)+self.rob(root.left.right)
        #     cand2+=self.rob(root.left)
        # if root.right:
        #     cand1+= self.rob(root.right.left)+self.rob(root.right.right)
        #     cand2+= self.rob(root.right)

        # self.mp[root]=max(cand1,cand2)
        # return self.mp[root]
        
