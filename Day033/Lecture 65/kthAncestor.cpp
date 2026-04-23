#include <bits/stdc++.h>
using namespace std;

// 1/5

struct Node
{
    int data;
    struct Node *left, *right;
};

// your task is to complete this function
class Solution {
  private:
    Node* solve(Node* root, int& k, int node) {
        
        /*
            k = 3
            node = 2
            1 2 7 3 6 N N N 4 N N 5
                    1
                   / \
                  2   7
                 /\   /\
                3  6  
               /\ / \
                4    5
                
                k = 1
                node = 3
                1 2 N N 3 4 5 N N N 6
                    1
                   / \
                  2   N
                 /\   /\
                N  3  
               /\ / \
                  4  5
                 / \ /\
                       6
        */
        if (root == NULL) {
            return NULL;
        }
        
        if (root->data == node) {
            return root;
        }
        
        Node* left = solve(root->left, k, node);
        Node* right = solve(root->right, k, node);
        
        if (left != NULL && right == NULL) {
            
            k--;
            if (k == 0) {
                return root;
            }
            else {
                return left;
            }
        }
        
        if (left == NULL && right != NULL) {
            
            k--;
            if (k == 0) {
                return root;
            }
            else {
                return right;
            }
        }
        return NULL;
    }
    
  public:
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        
        Node* resultNode = solve(root, k, node);
        
        if (resultNode == NULL || k > 0) return -1;
        return resultNode->data;
    }
};