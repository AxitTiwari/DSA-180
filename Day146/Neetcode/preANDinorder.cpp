// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/2026012853

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
    TreeNode* func(int &i, int s, int e, vector<int>& preorder, unordered_map<int, int> &get_idx) {

        if (s > e) return NULL;

        int element = preorder[i++];
        int idx = get_idx[element];

        TreeNode* node = new TreeNode(element);
        node->left = func(i, s, idx-1, preorder, get_idx);
        node->right = func(i, idx+1, e, preorder, get_idx);

        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> get_idx;
        for (int i = 0; i < inorder.size(); i++) {
           get_idx[inorder[i]] = i;
        }

        int n = inorder.size() - 1;
        int i = 0;
        return func(i, 0, n, preorder, get_idx);
    }
};