
// https://leetcode.com/problems/construct-string-from-binary-tree/submissions/2109817024

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
    string tree2str(TreeNode* root) {
        
        if (!root) return "";

        if (!root->left && !root->right) {
            return to_string(root->val);
        }

        string left = tree2str(root->left);
        string right = tree2str(root->right);
        
        string res = "";
        res += to_string(root->val);
        res += "(" + left + ")";
        if (right != "") res += "(" + right + ")";

        return res;
    }
};