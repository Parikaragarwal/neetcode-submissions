# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left==right:
            return head;
        dummy:ListNode = ListNode(0,head)
        curr:ListNode = dummy

        count:int = 0;
        while count<left-1:
            curr= curr.next;
            count+=1
        coach:ListNode = curr
        start:ListNode = curr.next
        prev:ListNode = curr
        next = start

        while count<right:
            curr = next
            count+=1
            next =next.next
            curr.next = prev
            prev = curr
        
        start.next = next
        coach.next = curr

        return dummy.next

        