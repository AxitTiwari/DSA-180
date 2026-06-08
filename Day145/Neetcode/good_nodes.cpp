// https://leetcode.com/problems/count-good-nodes-in-binary-tree/submissions/2025517202

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
    int f(TreeNode* root, int max_val) {

        if (root == NULL) return 0;

        int left = f(root->left, max(max_val, root->val));
        int right = f(root->right, max(max_val, root->val));

        return root->val >= max_val ? left + right + 1 : left + right;
    }
public:
    int goodNodes(TreeNode* root) {
        
        return f(root, root->val);
    }
};