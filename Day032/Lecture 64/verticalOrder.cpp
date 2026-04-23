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
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        
        map <int, map<int, vector<int> > > nodes;
        queue <pair<Node*, pair<int, int> > > q;
        
        vector<vector<int>> ans;
        
        if (root == NULL)
            return ans;
            
        // q = |{root, {0, 0}} |
        q.push(make_pair(root, make_pair(0, 0)));
        
        while (!q.empty()) {
            
            // #1. q = |{root, {0, 0}} |
            // #2. q = |{root->left(2), {-1, 1}, {root->right(3), {1, 1}} |
            // #3. q = |{root->right(3), {1, 1}, {root->left->left(4), {-2, 2}}, {root->left->right(5), {0, 2}} |

            pair<Node*, pair<int, int> > temp = q.front();
            q.pop();

            // #1. q = | |
            // #2. q = |{root->right(3), {1, 1}} |
            
            Node* frontNode = temp.first; // root(1), root->left(2)
            int hd = temp.second.first; // 0, -1
            int level = temp.second.second; // 0, 1
            
            nodes[hd][level].push_back(frontNode->data); 
            // #1. nodes[0][0] -> 1
            // #2. nodes[-1][1] -> 2
            
            if (frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, level+1))); 
            // #1. q = |{root->left(2), {-1, 1}} |
            // #2. q = |{root->right(3), {1, 1}, root->left->left(4), {-2, 2}} |
            
            if (frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1, level+1))); 

            // #1. q = |{root->left(2), {-1, 1}, {root->right(3), {1, 1}} |
            // #2. q = |{root->right(3), {1, 1}, {root->left->left(4), {-2, 2}}, {root->left->right(5), {0, 2}} |
        }
        
        for (auto i : nodes) {
    
            vector<int> column;
    
            for (auto j : i.second) {
                for (auto k : j.second) {
                    column.push_back(k);
                }
            }
            ans.push_back(column);
        }
        return ans;
    }
};