#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    
  private:
    pair<int, int> diameterFast(Node* root) {
        
        if (root == NULL) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
    }

  public:
    int diameter(Node* root) {
        // code here
        
        pair<int, int> ans = diameterFast(root);
        
        if (ans.first == 0) return 0;
        
        return ans.first-1;
    }
};