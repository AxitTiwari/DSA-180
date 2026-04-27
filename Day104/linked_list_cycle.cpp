// https://leetcode.com/problems/linked-list-cycle-ii/submissions/1989659286

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_map<ListNode*, ListNode*> map_node_next;

        while (head && head->next) {

            map_node_next[head] = head->next;

            if (map_node_next.find(head->next) != map_node_next.end()) {
                return map_node_next[head];
            }

            head = head->next;
        }
        return nullptr;
    }
};