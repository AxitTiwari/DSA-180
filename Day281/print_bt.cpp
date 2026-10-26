// https://leetcode.com/problems/print-binary-tree/submissions/2178766508

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
    vector<vector<string>> printTree(TreeNode* root) {
        
        int h = get_height(root), n = pow(2, h) - 1;

        vector<vector<string>> res(h, vector<string> (n, ""));
        res[0][(n-1)/2] = to_string(root->val);
        dfs(root, 0, (n-1)/2, h-1, res);
        return res;
    }
private:
    int get_height(TreeNode* root) {
        if (root == NULL) return 0;

        return max(get_height(root->left), get_height(root->right)) + 1;
    }

    void dfs(TreeNode* root, int r, int c, int h, vector<vector<string>>& res) {

        if (!root) return;

        if (root->left) {
            int new_r = r + 1, new_c = c - pow(2, h-r-1);
            res[new_r][new_c] = to_string(root->left->val);
            dfs(root->left, new_r, new_c, h, res);
        }

        if (root->right) {
            int new_r = r + 1, new_c = c + pow(2, h-r-1);
            res[new_r][new_c] = to_string(root->right->val);
            dfs(root->right, new_r, new_c, h, res);
        }
    }
};