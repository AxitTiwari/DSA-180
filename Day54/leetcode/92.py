## https://leetcode.com/problems/reverse-linked-list-ii/submissions/1941794507

from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:

        # if right == left:
        #     return head

        dummy = ListNode(0, head)

        # reach node at position left
        left_prev, cur = dummy, head
        for i in range(left - 1):
            left_prev = cur
            cur = cur.next
        
        # reverse from left to right
        prev = None
        for i in range(right - left + 1):
            temp_next = cur.next
            cur.next = prev
            prev = cur
            cur = temp_next
        
        # connect reaming links

        ## edge case
        # if not left_prev:
        #     dummy.next = cur
        #     return prev

        left_prev.next.next = cur
        left_prev.next = prev

        return dummy.next

        