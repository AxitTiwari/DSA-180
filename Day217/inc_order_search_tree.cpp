// https://leetcode.com/problems/increasing-order-search-tree/submissions/2111674570

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
    TreeNode* increasingBST(TreeNode* root) {
        
        vector<int> inorder;
        in(root, inorder);
        return buildTree(inorder);
    }
private:

    TreeNode* buildTree(vector<int>& inorder) {

        TreeNode* root = NULL;

        TreeNode* tmp;

        for (int value : inorder) {

            TreeNode* node = new TreeNode(value);

            if (!root) {
                root = tmp = node;
                continue;
            }

            tmp->right = node;
            tmp = tmp->right;
        }
        return root;
    }

    void in(TreeNode* root, vector<int>& inorder) {

        if (!root) return;

        in(root->left, inorder);
        inorder.push_back(root->val);
        in(root->right, inorder);
    }
};