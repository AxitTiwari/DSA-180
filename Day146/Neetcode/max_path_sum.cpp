// https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/2026086785

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
    vector<int> res;
    int dfs(TreeNode* root) {

        if (root == NULL) return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        res[0] = max(res[0], root->val + left + right);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        
        // fu*k this question.
        res.push_back(root->val);

        int sum = dfs(root);
        return max(sum, res[0]);
    }
};