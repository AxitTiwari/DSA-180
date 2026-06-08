// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int func(TreeNode* root, int k, int &i) {

       if (root == NULL) return -1;

       // inorder
       int left = func(root->left, k, i);

       if (left != -1) return left;

       i++;

    //    cout << "i: " << i << " val: " << root->val << endl;

       if (i == k) return root->val;

       return func(root->right, k, i);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        
        int i = 0;
        return func(root, k, i);
    }
};