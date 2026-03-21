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
  public:
    vector<int> bottomView(Node *root) {
        // code here
        
        vector<int> ans;
        
        if (root == NULL) {
            return ans;
        }
        
        map<int, int> topNode;
        queue <pair<Node*, int>> q;
        
        q.push(make_pair(root, 0));
        
        while (!q.empty()) {
            pair <Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int horizontalDistance = temp.second;
            
            // "If new horizontal distance apperead then replace old one with it"
            topNode[horizontalDistance] = frontNode->data;
                
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, horizontalDistance-1));
            }
            
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, horizontalDistance+1));
            }
        }
        for (auto i : topNode) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};