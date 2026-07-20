
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
    int countDominantNodes(TreeNode* root) {

        return func(root).first;
    }
private:
    pair<int, int> func(TreeNode* root) {

        if (root == NULL) return {0, 0};

        auto left = func(root->left);
        auto right = func(root->right);

        if (root->val >= left.second and root->val >= right.second)
            return {left.first + right.first + 1, root->val};
        return {left.first + right.first, max(left.second, right.second)};
    }
};