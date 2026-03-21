#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        
        vector<int> result;
        
        if (root == NULL) {
            return result;
        }
        
        // ----push first element-----
        queue<Node*> q;
        q.push(root);
        
        // -----inidtial direction-----
        bool leftToRight = true;
        while (!q.empty()) {
            
            // ------size of every level------
            int size = q.size();
            vector<int> ans(size);
            
            // -----level process-----
            for (int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();
                
                // ------insert value at correct index of  temp vector----
                int index = leftToRight ? i : size-i-1;
                ans[index] = frontNode->data;
                
                // ------insert all next level values to the queue-------
                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }
            
            // ----change direction----
            leftToRight = !leftToRight;
            
            // store temp ans in reult;
            for (auto i : ans)
                result.push_back(i);
        }
        return result;
    }
};