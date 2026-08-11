// https://leetcode.com/problems/find-mode-in-binary-search-tree/submissions/2103226384

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
    vector<int> findMode(TreeNode* root) {
        
        vector<int> in;
        inorder(root, in);

        unordered_map<int, int> cnt;
        for (int val : in) {
            cnt[val]++;
        }

        int max = get_max(cnt);

        vector<int> res;
        for (auto &it : cnt) {
            if (it.second == max) res.push_back(it.first);
        }
        return res;
    }
private:

    int get_max(unordered_map<int, int>& cnt) {

        int max = INT_MIN;
        for (auto &it : cnt) {

            if (it.second > max) max = it.second;
        }
        return max;
    }

    void inorder(TreeNode* root, vector<int>& in) {

        if (!root) return;

        in.push_back(root->val);
        inorder(root->left, in);
        inorder(root->right, in);
    }
};