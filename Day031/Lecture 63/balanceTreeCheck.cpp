#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
    int height(Node* root) {
        
        if (root == NULL) {
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        int ans = max(left, right) + 1;
        
        return ans;
    }
    
  public:
    bool isBalanced(Node* root) {
        // code here
        
        // 4 N 8 N 5 9 9
        if (root == NULL) {
            return true;
        }
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool heightDiff = abs(height(root->left) - height(root->right)) <= 1;
        
        if (left && right && heightDiff) {
            return true;
        }
        return false;
    }
};