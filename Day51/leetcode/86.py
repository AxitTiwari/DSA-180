## https://leetcode.com/problems/partition-list/submissions/1938862651

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:

        left, right = ListNode(), ListNode()

        ltail, rtail = left, right

        while head:
            if head.val < x:
                ltail.next = head
                ltail = ltail.next
            else:
                rtail.next = head
                rtail = rtail.next
            head = head.next
        
        ltail.next = right.next  ## now link
        rtail.next = None ## edge case don't forget otherwise cycle is going to create
        return left.next
        