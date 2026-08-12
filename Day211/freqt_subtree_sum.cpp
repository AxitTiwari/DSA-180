// https://leetcode.com/problems/most-frequent-subtree-sum/submissions/2104445067

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
    unordered_map<int, int> cnt;
    int max_cnt;

    Solution() {max_cnt = 0;}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        dfs(root);
        vector<int> res;
        for (auto& it: cnt) {
            if (it.second == max_cnt) {res.push_back(it.first);}
        }
        return res;
    }

private:
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int sum = dfs(root->left) + root->val + dfs(root->right);
        max_cnt = max(max_cnt, ++cnt[sum]);
        return sum;
    }
};