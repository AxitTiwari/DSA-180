// https://leetcode.com/problems/symmetric-tree/submissions/2069695091

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
    bool isSymmetric(TreeNode* root) {
        
        if (root == nullptr) return true;

        if (root->left == nullptr and root->right == nullptr) return true;

        return isSameTree(root->left, root->right);
    }
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if (p == NULL and q == NULL) return true;

        if (p == NULL || q == NULL) return false;

        if (p->val != q->val) return false;

        return isSameTree(p->left, q->right) and isSameTree(p->right, q->left);
    }
};