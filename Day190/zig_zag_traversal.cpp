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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if (root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);

        bool left = true;
        while (!q.empty()) {

            int size = q.size();

            vector<int> order(size);
            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                int idx = left ? i : size - i - 1;
                order[idx] = node->val;

                if (node->left) q.push(node->left);

                if (node->right) q.push(node->right);
            }
            res.push_back(order);
            left = !left;
        }
        return res;
    }
};