// https://leetcode.com/problems/linked-list-cycle-ii/submissions/2055398366

// **imp
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
        
        if (head == NULL) return NULL;

        // **imp (don't forget bro)
        ListNode *slow = head, *fast = head;
        while (fast->next and fast->next->next) {

            slow = slow->next, fast = fast->next->next;

            if (slow == fast) {
                fast = head;
                while (slow != fast) slow = slow->next, fast = fast->next;
                return slow;
            }
            
        }
        return NULL;
    }
};