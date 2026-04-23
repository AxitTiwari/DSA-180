## https://leetcode.com/problems/insertion-sort-list/submissions/1942130975

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        dummy = ListNode(0, head)

        """
            0 4 2 1 3
            prev = 4
            cur = 2

        """
        prev, cur = head, head.next
        while cur:
            print("before")

            ## if value at its correct position then skip
            if cur.val >= prev.val:
                prev, cur = cur, cur.next
                continue
            
            print("after")
            insert_cur_after = dummy
            while cur.val > insert_cur_after.next.val:
                insert_cur_after = insert_cur_after.next
            
            prev.next = cur.next
            cur.next = insert_cur_after.next
            insert_cur_after.next = cur
            cur = prev.next

        return dummy.next