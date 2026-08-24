// https://leetcode.com/problems/check-completeness-of-a-binary-tree/submissions/2118654957

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
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);

        bool found_null = false;

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                found_null = true;
                continue;
            }

            if (found_null) return false;

            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
};