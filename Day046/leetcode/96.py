## https://leetcode.com/problems/unique-binary-search-trees/submissions/1933230192

class Solution:
    def numTrees(self, n: int) -> int:
        ## DP
        
        # numTree[3] = numTree[0] * numTree[2] +
        #                numTree[1] * numTree[1] +
        #                numTree[2] * numTree[0]

        
        numTree = [1] * (n + 1)
        
        # 0 node = 1 Tree
        # 1 node = 1 Tree
        for node in range(2, n+1):
            total = 0
            for root in range(1, node+1):
                left = root - 1
                right = node - root
                total += numTree[left] * numTree[right]
            numTree[node] = total
        return numTree[n]

        