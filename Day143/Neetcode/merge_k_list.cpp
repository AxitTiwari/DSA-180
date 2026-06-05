// https://leetcode.com/problems/merge-k-sorted-lists/submissions/2023267165

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare {
public:
    bool operator()(ListNode* first, ListNode* second) {
        return first->val > second->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare> min_heap;

        int k = lists.size();
        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL)
                min_heap.push(lists[i]);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;
        while (!min_heap.empty()) {

            ListNode* node = min_heap.top();
            min_heap.pop();

            if (node->next) min_heap.push(node->next);

            if (head == NULL) {
                head = tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }
        return head;
    }
};