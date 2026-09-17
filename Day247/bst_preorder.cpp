// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/2144281316

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        stack<int> st;
        
        TreeNode* tree = NULL, *ptr = NULL;
        for (int i = 0; i < preorder.size(); i++) {

            int node = -1;
            while (!st.empty() && st.top() < preorder[i]) {

                node = st.top();
                st.pop();
            }

            if (node != -1) {
                ptr = add_at_right(&tree, node, preorder[i]);

                // cout << ptr->val << endl;
            }
            else {

                TreeNode* new_node = new TreeNode(preorder[i]);
                if (!tree) {
                    tree = new_node;
                    ptr = new_node;
                }
                else {

                    ptr->left = new_node;
                    ptr = ptr->left;
                }
            }
            st.push(preorder[i]);
        }
        return tree;
    }

private:
    TreeNode* add_at_right(TreeNode** tree, int after, int value) {

        if ((*tree)->val == after) {
            (*tree)->right =  new TreeNode(value);
            
            return (*tree)->right;
        }

        if ((*tree)->val > after) {
            return add_at_right(&((*tree)->left), after, value);
        }
        else {
            return add_at_right(&((*tree)->right), after, value);
        }
    }
};