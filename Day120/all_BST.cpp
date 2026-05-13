// https://leetcode.com/problems/unique-binary-search-trees-ii/submissions/2002259932

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
    vector<TreeNode*> f(int s, int e) {

        vector<TreeNode*> ans;

        if (s > e) {
            return {nullptr};
        }


        for (int i = s; i <= e; i++) {

            vector<TreeNode*> left = f(s, i-1);
            vector<TreeNode*> right = f(i+1, e);

            for (auto l : left) {
                for (auto r : right) {

                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        
        return f(1, n);
    }
};