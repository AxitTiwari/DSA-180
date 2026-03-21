## https://leetcode.com/problems/diameter-of-binary-tree/submissions/1933906339
from pyparsing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        res = [0]

        def dfs(root):
            if not root:
                return -1
            
            left = dfs(root.left)
            right = dfs(root.right)

            ## dia
            res[0] = max(res[0], 2 + left + right)

            ## height
            return 1 + max(left, right)
        
        dfs(root)
        return res[0]
        