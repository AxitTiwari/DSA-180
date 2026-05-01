// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/submissions/1992751760

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
    vector<vector<int>> bfs(TreeNode* root) {

        if (root == NULL) {
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;

        while (!q.empty()) {

            int size = q.size();

            vector<int> level_nodes;

            // loop every node at the current level
            while (size) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }

                level_nodes.push_back(node->val);
                size--;
            }

            // push every level data
            ans.push_back(level_nodes);
        }

        // reverse the order -> we added it from start not end
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        return bfs(root);
    }
};