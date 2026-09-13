# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isLeaf(self,root)->bool:
        return not root.left and not root.right
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return None
        if key<root.val:
           root.left = self.deleteNode(root.left,key)
        elif key>root.val:
           root.right = self.deleteNode(root.right,key)
        else:
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            
            prev = root
            successor = root.right
            while successor.left:
                prev = successor
                successor = successor.left
            root.val = successor.val
            if successor == prev.left:
                prev.left = self.deleteNode(successor,successor.val)
            else:
                prev.right = self.deleteNode(successor,successor.val)
                
        return root