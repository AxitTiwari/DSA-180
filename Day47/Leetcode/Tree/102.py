## https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/1934328222

from typing import Optional, List
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        res = []

        q = collections.deque([root])
        while q:
            qLen = len(q)
            level = []
            for i in range(qLen):
                node = q.popleft()

                if node:
                    q.append(node.left)
                    q.append(node.right)
                    level.append(node.val)
            
            if level:
                res.append(level)
        
        return res

        