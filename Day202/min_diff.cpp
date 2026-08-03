// https://leetcode.com/submissions/detail/2092056846/

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
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> inorder;
        in(root, inorder);

        int res = INT_MAX;
        for (int i = 1; i < inorder.size(); i++) {

            int diff = inorder[i] - inorder[i-1];
            res = min(res, diff);
        }
        return res;
    }
private:
    void in(TreeNode* root, vector<int>& inorder) {

        if (root == NULL) return;

        in(root->left, inorder);
        inorder.push_back(root->val);
        in(root->right, inorder);
    }
};