## https://leetcode.com/problems/rotate-list/submissions/1940359748

from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return head
        
        ## 1 ,2 ,3 ,4 ,5 None
        length, tail = 1, head
        while tail.next:
            length += 1
            tail = tail.next
        
        print(length)

        k = k % length

        if k == 0:
            return head
        
        cur = head
        for i in range(length-k-1):
            cur = cur.next
        
        new_head = cur.next
        cur.next = None
        tail.next = head
        return new_head
        