## https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/1935744265

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head:
            return head
        
        # if not head.next and n == 1:
        #     return None
        
        dummy = ListNode(0, head)
        
        left = dummy
        right = head
        ## keep a distance of n between left and right
        while right and n:
            right = right.next
            n -= 1
        
        ## move right and slow, until right becomes None
        while right:
            left = left.next 
            right = right.next

        # 0 1 2 3 4 5 None
        # 0 1 2 None
        # 0 1 None

        left.next = left.next.next
        return dummy.next

        

        