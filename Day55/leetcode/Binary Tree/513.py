## https://leetcode.com/problems/find-bottom-left-tree-value/submissions/1942816465

from typing import Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        q = deque([root])

        while q:

            ## pyhton do NOT create scopes of the variables like c/cpp/java
            # so this variable is accesable throughout the function
            node = q.popleft()

            ## move left < -------- right
            if node.right:
                q.append(node.right)
            if node.left:
                q.append(node.left)
        
        return node.val
        