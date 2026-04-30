// https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/1991712549

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
    int bfs(TreeNode* root) {

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int depth = it.second;

            if (node->left == NULL && node->right == NULL) return depth;

            if (node->left) {
                int depth = it.second;
                q.push({node->left, ++depth});
            }

            if (node->right) {
                int depth = it.second;
                q.push({node->right, ++depth});
            }
        }
        return -1;
    }

public:
    int minDepth(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }
        
        return bfs(root);
    }
};