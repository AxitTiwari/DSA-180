// https://leetcode.com/problems/maximum-binary-tree/submissions/2119348630

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
    unordered_map<int, int> get_idx;

    TreeNode* f(vector<int>& nums, int s, int e) {

        if (s > e) return NULL;

        int m = max_num(nums, s, e);

        int idx = get_idx[m];

        TreeNode* node = new TreeNode(m);
        node->left = f(nums, s, idx-1);
        node->right = f(nums, idx+1, e);
        return node;
    }

    int max_num(vector<int>& nums, int s, int e) {

        int res = INT_MIN;
        for (int i = s; i <= e; i++) {
            if (res < nums[i]) res = nums[i];
        }
        return res;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            get_idx[nums[i]] = i; 
        }

        return f(nums, 0, nums.size()-1);

    }
};