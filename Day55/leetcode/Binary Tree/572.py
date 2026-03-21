## https://leetcode.com/problems/subtree-of-another-tree/submissions/1942788555

from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        ## check whther two tree's are the same
        def same_tree(self, root, subRoot):
            if not root and not subRoot:
                return True
                
            if root and subRoot and root.val == subRoot.val:
                return (self.same_tree(root.left, subRoot.left) and 
                        self.same_tree(root.right, subRoot.right))

            return False
        
        if not subRoot: return True
        if not root: return False

        ## check whether this cur node tree and subroot tree are the same ? if yes then return true , otherwise,
        if self.same_tree(root, subRoot):
            return True
        
        ## check for every node that from this node whether, node tree and subroot tree are the same
        return (self.isSubtree(root.left, subRoot) or
                self.isSubtree(root.right, subRoot))