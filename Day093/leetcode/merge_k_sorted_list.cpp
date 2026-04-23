// https://leetcode.com/problems/merge-k-sorted-lists/submissions/1979698565

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

    // compare two nodes by there data values
    bool operator()(ListNode* first, ListNode* second) {
        return first->val > second->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> min_heap;

        int k = lists.size();

        if (k == 0) return NULL;

        // step1: 
        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                min_heap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (min_heap.size() > 0) {

            ListNode* top = min_heap.top();
            min_heap.pop();

            if (top->next) {
                min_heap.push(top->next);
            }

            if (head == NULL) {
                head = top;
                tail = top;
            }
            else {

                tail->next = top;
                tail = top;
            }
        }
        return head;
    }
};