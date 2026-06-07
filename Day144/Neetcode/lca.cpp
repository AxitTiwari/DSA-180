// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL) return NULL;
        if (root == p || root == q) return root;

        TreeNode* n1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* n2 = lowestCommonAncestor(root->right, p, q);

        if (n1 && n2) return root;
        else if (n1) return n1;
        else if (n2) return n2;
        else return NULL;
    }
};