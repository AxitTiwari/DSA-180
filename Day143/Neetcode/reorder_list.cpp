// https://leetcode.com/problems/reorder-list/submissions/2022829400

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

    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return head = prev;
    }

    void reorderList(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tail = slow->next;
        slow->next = NULL;
        tail = reverseList(tail);

        while (head && tail) {

            ListNode* head_next = head->next;
            ListNode* tail_next = tail->next;

            tail->next = head->next;
            head->next = tail;

            head = head_next;
            tail = tail_next;
        }
        head = dummy.next;
    }
};