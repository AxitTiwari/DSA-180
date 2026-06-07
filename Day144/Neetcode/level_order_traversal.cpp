// https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/2024209852

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (root == NULL) return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {

            int size = q.size();

            vector<int> order;
            while (size) {

                TreeNode* top = q.front();
                q.pop();

                order.push_back(top->val);

                if (top->left) {
                    q.push(top->left);
                }

                if (top->right) {
                    q.push(top->right);
                }

                size--;
            }
            ans.push_back(order);
        }
        return ans;
    }
};