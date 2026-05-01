// https://leetcode.com/problems/binary-tree-paths/submissions/1992244485

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

    string refine(string& s) {

        string ans;

        for (int i = 0; i < s.length()-1; i++) {

            ans += s[i];
            ans += "->";
        }
        ans += s[s.length()-1];
        return ans;
    }

    void dfs(TreeNode* root, string s, vector<string>& ans) {

        // no need of backtracking if string is passed not by - reference.
        // BUT do it with backtacking.

        if (root == NULL) {
            return;
        }

        s += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(s);
            // s.pop_back();
            return;
        }

        s += "->";

        dfs(root->left, s, ans);
        dfs(root->right, s, ans);

        // remove last num and "->"
        // s.pop_back();
        // s.pop_back();
        // s.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        string s;
        vector<string> ans;

        dfs(root, s, ans);
        return ans;
    }
};