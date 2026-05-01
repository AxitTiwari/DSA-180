// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/1992422161

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
    int post_index = 0;
    unordered_map<int, int> mp;

    int get_index(vector<int>& inorder, int target) {

        int i = 0;
        for (auto node : inorder) {

            if (node == target) {
                return i;
            }
            i++;
        }
        return -1;
    }
    
    TreeNode* f(int start, int end, vector<int>& inorder, vector<int>& postorder) {

        if (start > end || start < 0) {
            return nullptr;
        }

        TreeNode* new_node = new TreeNode(postorder[post_index++]);

        int node_index = mp[new_node->val];

        new_node->right = f(node_index+1, end, inorder, postorder);
        new_node->left = f(start, node_index-1, inorder, postorder);

        return new_node;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        reverse(postorder.begin(), postorder.end());
        return f(0, inorder.size()-1, inorder, postorder);
    }
};