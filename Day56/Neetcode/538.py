## https://leetcode.com/problems/convert-bst-to-greater-tree/submissions/1944061162

from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        cur_sum = 0

        def dfs(node):

            if not node:
                return
            
            nonlocal cur_sum
            dfs(node.right)
            tmp = node.val
            node.val += cur_sum
            cur_sum += tmp
            dfs(node.left)

        dfs(root)
        return root
        