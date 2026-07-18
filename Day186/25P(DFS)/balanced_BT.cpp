// https://leetcode.com/problems/balanced-binary-tree/submissions/2072266056

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
    bool isBalanced(TreeNode* root) {
        return func(root).first;
    }
private:
    pair<bool, int> func(TreeNode* root) {

        if (root == NULL) return {true, 0};

        auto [is_left_balanced, left_depth] = func(root->left);
        auto [is_right_balanced, right_depth] = func(root->right);

        if (abs(left_depth - right_depth) > 1) return {false, max(left_depth, right_depth)+1};
        return {is_left_balanced and is_right_balanced, max(left_depth, right_depth)+1};
    }
};