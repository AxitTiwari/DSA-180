// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* r = head;
        while (n) {
            r = r->next;
            n--;
        }

        ListNode* l = dummy;
        while (r) {
            l = l->next;
            r = r->next;
        }

        ListNode* node_to_delet = l->next;
        l->next = node_to_delet->next;
        delete(node_to_delet);

        return dummy->next;
    }
};