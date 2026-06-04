// https://leetcode.com/problems/merge-two-sorted-lists/submissions/2022524450

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {

            int val;
            if (list1->val < list2->val) {
                val = list1->val;
                list1 = list1->next;
            }
            else {
                val = list2->val;
                list2 = list2->next;
            }

            ListNode* node = new ListNode(val);
            tail->next = node;
            tail = tail->next;
        }

        while (list1) {
            tail->next = new ListNode(list1->val);
            tail = tail->next;
            list1 = list1->next;
        }

        while (list2) {
            tail->next = new ListNode(list2->val);
            tail = tail->next;
            list2 = list2->next;
        }
        return dummy.next;
    }
};
