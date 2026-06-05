// https://leetcode.com/problems/add-two-numbers/submissions/2022977515

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if (!l1 && !l2) return NULL;

        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* n1 = l1;
        ListNode* n2 = l2;

        int sum = n1->val + n2->val;
        int digit = sum % 10;
        int carry = sum / 10;
        
        ListNode* addition = new ListNode(digit);
        ListNode* head = addition;

        n1 = n1->next;
        n2 = n2->next;
        while (n1 && n2) {

            sum = n1->val + n2->val + carry;
            digit = sum % 10;
            carry = sum / 10;

            ListNode* new_node = new ListNode(digit);
            head->next = new_node;
            head = head->next;

            n1 = n1->next;
            n2 = n2->next;
        }

        while (n1) {
            sum = n1->val + carry;
            digit = sum % 10;
            carry = sum / 10;

            ListNode* new_node = new ListNode(digit);
            head->next = new_node;
            head = head->next;

            n1 = n1->next;
        }

        while (n2) {
            sum = n2->val + carry;
            digit = sum % 10;
            carry = sum / 10;

            ListNode* new_node = new ListNode(digit);
            head->next = new_node;
            head = head->next;

            n2 = n2->next;
        }

        if (carry > 0) {
            ListNode* new_node = new ListNode(carry);
            head->next = new_node;
        }
        return addition;
    }
};
