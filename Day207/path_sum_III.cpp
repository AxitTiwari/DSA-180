// https://leetcode.com/problems/path-sum-iii/submissions/2098734159

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        
        if (!root) return 0;
        
        // start a new path from left & right and start creating path from this node;
        return pathSum(root->left, targetSum) + path_sum(root, targetSum) + pathSum(root->right, targetSum);
    }

private:
    int path_sum(TreeNode* root, long long target) {

        if (!root) return 0;

        long long res = 0;
        if (root->val == target) res += 1;

        res += path_sum(root->left, target-root->val);
        res += path_sum(root->right, target-root->val);
        return res;
    }
};