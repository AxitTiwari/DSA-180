// https://leetcode.com/problems/clone-graph/submissions/2029735681

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    unordered_map<Node*, bool> visited; // i could avoid this, and you should do it now

    Node* cloneGraph(Node* node) {

        if (node == NULL) return NULL;

        if (visited[node]) {
            return mp[node];
        }

        visited[node] = true;
        
        Node* temp = new Node(node->val);
        mp[node] = temp;

        for (auto nbr : node->neighbors) {

            temp->neighbors.push_back(cloneGraph(nbr));
        }
        return temp;
    }
};