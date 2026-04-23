## https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/1933075835

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:

        def dfs(cur, pathSum):
            if not cur:
                return 0
            
            pathSum = pathSum * 10 + cur.val

            ## *** leaf node ***
            if not cur.left and not cur.right:
                return pathSum

            return dfs(cur.left, pathSum) + dfs(cur.right, pathSum)
        
        return dfs(root, 0)

        #       1
        #      / \
        #     2   3
        # pathSum = 0 1 12
        # pathSum = 0 1 13
        # 12 + 13 -> 25 
        