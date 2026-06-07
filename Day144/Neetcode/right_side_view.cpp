// https://leetcode.com/problems/binary-tree-right-side-view/submissions/2024454527

// go to love babbar notes for this, for better understanding of the question and the approach
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
    vector<int> rightSideView(TreeNode* root) {
        
        if (!root) return {};

        vector<int> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {

            int size = q.size();

            vector<int> order;

            while (size) {

                TreeNode* front = q.front();
                q.pop();

                order.push_back(front->val);

                if (front->right) {
                    q.push(front->right);
                }

                if (front->left) {
                    q.push(front->left);
                }
                size--;
            }
            ans.push_back(order[0]);
        }
        return ans;
    }
};