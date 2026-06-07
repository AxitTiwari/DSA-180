// https://leetcode.com/problems/invert-binary-tree/submissions/2023782338

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
private:
    TreeNode* f(TreeNode* root) {

        if (root == NULL) return root;

        TreeNode* left = f(root->left);
        TreeNode* right = f(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return f(root);
    }
};
