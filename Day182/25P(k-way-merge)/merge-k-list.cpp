// https://leetcode.com/problems/merge-k-sorted-lists/submissions/2067613860

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class compaire {
public:
    bool operator() (ListNode *first, ListNode *second) {
        return first->val > second->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compaire> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) pq.push(lists[i]);
        }

        ListNode *head = NULL;
        ListNode *tail = NULL;

        while (!pq.empty()) {

            ListNode *node = pq.top();
            pq.pop();

            if (head == NULL) {
                head = tail = node;
            }
            else {
                tail->next = node;
                tail = tail->next;
            }

            if (node and node->next) pq.push(node->next);
        }
        return head;
    }
};