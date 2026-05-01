// https://leetcode.com/problems/path-sum-ii/submissions/1992786206

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
    vector<vector<int>> path_of_sum;
    void dfs(TreeNode* root, int target_sum, vector<int>& one_path, int sum) {

        if (root == NULL) return;

        one_path.push_back(root->val);
        sum += root->val;

        if (root->left == NULL && root->right == NULL) {

            if (sum == target_sum) {
                path_of_sum.push_back(one_path);
            }

            // backtrack
            one_path.pop_back();
            return;
        }

        dfs(root->left, target_sum, one_path, sum);
        dfs(root->right, target_sum, one_path, sum);

        one_path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        // easy ! 🫡😎
        vector<int> path;
        dfs(root, targetSum, path, 0);

        return path_of_sum;
    }
};