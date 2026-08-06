// https://leetcode.com/problems/count-complete-tree-nodes/submissions/2096884363

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
    int countNodes(TreeNode* root) {
        
        if (!root) return 0;

        int lh = left_height(root), rh = right_height(root);

        // perfect binary tree -> height : 2 ^ h - 1;
        if (lh == rh) return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
private:
    int left_height(TreeNode* root) {
        if (!root) return 0;
        return 1 + left_height(root->left);
    }

    int right_height(TreeNode* root) {
        if (!root) return 0;
        return 1 + right_height(root->right);
    }
};