## https://leetcode.com/problems/copy-list-with-random-pointer/submissions/1940109049

from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        oldToCopy = {None: None}

        old = head
        while old:
            copy = Node(old.val)
            oldToCopy[old] = copy
            old = old.next
        
        old = head
        while old:
            copy = oldToCopy[old]
            copy.next = oldToCopy[old.next]
            copy.random = oldToCopy[old.random]

            old = old.next
        
        return oldToCopy[head]
        