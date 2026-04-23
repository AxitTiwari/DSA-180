#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  private:
    pair<int, int> solve(Node* root) {
        
        if (root == NULL) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        pair<int, int> result;
        
        // including current node -> excluding left and right
        result.first = root->data + left.second + right.second;
        
        // excluding current node -> including left & right, inclu left exclu right,
        // excluding left including right, excluding both
        // these all are 4 possiblities pick one that has maximum sum
        result.second = max(left.first, left.second) + max(right.first, right.second);
        return result;
    }
    
  public:
    int getMaxSum(Node *root) {
        
        // pair of sum- first including the node second excluding the node
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};