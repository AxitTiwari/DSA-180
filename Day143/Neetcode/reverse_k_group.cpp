// https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/2023458681

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (!head) return NULL;

        int cnt = 0;
        ListNode* cur = head;

        while (cur && cnt < k) {
            cnt++;
            cur = cur->next;
        }

        if (cnt != k) return head;

        cur = head;
        cnt = 0;
        ListNode* prev = NULL;
        ListNode* next;
        while (cur && cnt < k) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;

            cnt++;
        }

        if (next) {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};