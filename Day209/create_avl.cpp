// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/submissions/2101905284

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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
    TreeNode* sortedListToBST(ListNode* head) {

        if (head == nullptr) return nullptr;
        
        TreeNode* root = nullptr;
        while (head) {

            root = push_value(root, head->val);
            head = head->next;
        }
        return root;
    }
private:
    unordered_map<TreeNode*, int> height;
    TreeNode* push_value(TreeNode* root, int val) {

        if (!root) {
            TreeNode* node = new TreeNode(val);
            height[node] = 1;
            return node;
        }

        if (root->val < val) {
            root->right = push_value(root->right, val);
        }
        else if (root->val > val) {
            root->left = push_value(root->left, val);
        }
        else {
            return root;
        }

        height[root] = 1 + max(get_height(root->left), get_height(root->right));

        int balance_factor = get_balance(root);

        // LL

        if (balance_factor > 1 && val < root->left->val) {
            return right_rotate(root);
        }
        else if (balance_factor < -1 && val > root->right->val) {

            // RR
            return left_rotate(root);
        }
        else if (balance_factor > 1 && val > root->left->val) {

            // LR
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
        else if (balance_factor < -1 && val < root->right->val) {

            root->right = right_rotate(root->right);
            return left_rotate(root);
            // RL
        }
        return root;

    }

    // right rotation
    TreeNode* right_rotate(TreeNode* root) {

        TreeNode* child = root->left;
        TreeNode* child_right = child->right;
        
        child->right = root;
        root->left = child_right;

        height[root] = 1 + max(get_height(root->left), get_height(root->right));
        height[child] = 1 + max(get_height(child->left), get_height(child->right));
        return child;
    }

    TreeNode* left_rotate(TreeNode* root) {

        TreeNode* child = root->right;
        TreeNode* child_left = child->left;
        
        child->left = root;
        root->right = child_left;

        height[root] = 1 + max(get_height(root->left), get_height(root->right));
        height[child] = 1 + max(get_height(child->left), get_height(child->right));
        return child;
    }

    int get_balance(TreeNode* root) {

        if (!root) return 0;
        return height[root->left] - height[root->right];
    }

    int get_height(TreeNode* root) {
        if (!root) return 0;

        return height[root];
    }
};