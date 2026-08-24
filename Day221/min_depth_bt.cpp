// https://leetcode.com/submissions/detail/2116376516/

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
    int minDepth(TreeNode* root) {

        if (!root) return 0;

        return f(root);
    }
    int f(TreeNode* root) {

        if (!root) return INT_MAX;

        if (!root->left and !root->right) return 1;

        return min(f(root->left), f(root->right)) + 1;
    }
};