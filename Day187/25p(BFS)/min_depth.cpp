// https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/2073156862

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
         
         // ** do it with BFS bro plz, no need of DFS here...
        if (root == NULL) return 0;
        return func(root);
    }
private:
    int func(TreeNode* root) {

        if (root == NULL) return INT_MAX;

        if (root->left == NULL and root->right == NULL) return 1;

        return min(func(root->left), func(root->right)) + 1;
    }
};