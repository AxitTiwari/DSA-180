// https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/2068261991

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
    int maxDepth(TreeNode* root) {
        
        return func(root);
    }
private:
    int func(TreeNode *root) {

        if (root == NULL) return 0;

        int left = func(root->left);
        int right = func(root->right);
        
        return max(left, right) + 1;
    }
};