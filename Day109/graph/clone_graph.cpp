// https://leetcode.com/problems/clone-graph/submissions/1993551094

#include <bits/stdc++.h>
using namespace std;

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
    unordered_map<Node*, Node*> mp; // (node, clone)

    Node* dfs(Node* node) {

        // if already visited
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }

        // clone the node
        Node* clone = new Node(node->val);

        // store the mapping, -> helps when revisit a visited node
        mp[node] = clone;

        for (auto nbr : node->neighbors) {

            // push the nbr into clone, but before pushing lets complete it by calling dfs, -> for all links
            clone->neighbors.push_back(dfs(nbr));
        }

        // return node that is completed in terms of its connections
        return clone;
    }

    Node* cloneGraph(Node* node) {
        
        // NOT a simple problem !

        if (node == NULL) return NULL;

        return dfs(node);
    }
};