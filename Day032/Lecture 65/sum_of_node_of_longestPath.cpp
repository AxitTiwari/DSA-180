#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; 

class Solution {
  private:
    void solve(Node* root, int sum, int& maxSum, int level, int& maxLevel) {
        
        if (root == NULL) {
            
            if (level > maxLevel) {
                maxLevel = level;
                maxSum = sum;
            }
            else if (level == maxLevel){
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        sum = sum + root->data;
        
        solve(root->left, sum, maxSum, level+1, maxLevel);
        solve(root->right, sum, maxSum, level+1, maxLevel);
    }
    
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        
        int level = 0;
        int maxLevel = 0;
        
        int sum = 0;
        int maxSum = 0;
        
        solve(root, sum, maxSum, level, maxLevel);
        return maxSum;
        
    }
};