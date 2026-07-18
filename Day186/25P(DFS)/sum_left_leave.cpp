// https://leetcode.com/problems/sum-of-left-leaves/submissions/2071941102

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
    int sumOfLeftLeaves(TreeNode* root) {
        
        return func(root, false);
    }
private:
    int func(TreeNode* root, bool is_left) {

        if (root == NULL) return 0;

        if (is_left) {
            if (root->left == NULL and root->right == NULL) return root->val;
        }

        return func(root->left, true) + func(root->right, false);
    }
};