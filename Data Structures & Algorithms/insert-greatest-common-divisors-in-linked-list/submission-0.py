# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head

        if curr.next == None:
            return head

        nxt = curr.next

        while nxt:

            ins = ListNode(math.gcd(curr.val,nxt.val))
            curr.next = ins
            ins.next = nxt

            curr = nxt
            nxt = nxt.next
        
        return head
        