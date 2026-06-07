// https://leetcode.com/problems/balanced-binary-tree/submissions/2023878091

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
    pair<int, bool> f(TreeNode* root) {

        if (root == NULL) return {0, true};

        auto left = f(root->left);
        auto right = f(root->right);

        int diff = left.first > right.first ? left.first - right.first : right.first - left.first;

        if (diff <= 1) return {max(left.first, right.first) + 1, true && left.second && right.second};

        return {max(left.first, right.first) + 1, false};
    }

public:
    bool isBalanced(TreeNode* root) {
        
        return f(root).second;
    }
};