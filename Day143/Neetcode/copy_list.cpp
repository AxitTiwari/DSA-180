// https://leetcode.com/problems/copy-list-with-random-pointer/submissions/2022948243

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, Node*> copy_node;

        Node* cur = head;
        while (cur) {
            copy_node[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            Node* copy = copy_node[cur];
            copy->next = copy_node[cur->next];
            copy->random = copy_node[cur->random];

            cur = cur->next;
        }
        return copy_node[head];
    }
};