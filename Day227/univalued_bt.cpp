// https://leetcode.com/submissions/detail/2123081835/
#include <bits\stdc++.h>
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
    bool isUnivalTree(TreeNode* root) {
        
        return f(root, root->val);
    }

private:
    bool f(TreeNode* root, int val) {

        if (root == NULL) return true;

        if (root->val != val) return false;

        return f(root->left, val) && f(root->right, val);
    }
};