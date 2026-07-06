// https://leetcode.com/problems/middle-of-the-linked-list/submissions/2055633585

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
    ListNode* middleNode(ListNode* head) {

        if (!head) return NULL;
        
        ListNode *slow = head, *fast = head;
        while (fast and fast->next) slow = slow->next, fast = fast->next->next;
        return slow;
    }
};