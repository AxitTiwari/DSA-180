// https://leetcode.com/problems/recover-binary-search-tree/submissions/2095640087

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

    void recoverTree(TreeNode* root) {

        func(root);
        swap(first->val, second->val);
    }
private:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void func(TreeNode* node) {

        if (!node) return;

        func(node->left);

        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }

        prev = node;
        func(node->right);
    }
};