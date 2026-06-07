// https://leetcode.com/problems/subtree-of-another-tree/submissions/2024047411
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if (p == NULL && q == NULL) return true;

        if (p == NULL) return false;

        if (q == NULL) return false;

        if (p->val != q->val) return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return left && right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if (root == NULL) return false;

        bool same = isSameTree(root, subRoot);

        if (same) return true;

        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);

        return left || right;
    }
};
