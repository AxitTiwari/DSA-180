
// https://leetcode.com/problems/remove-nodes-from-linked-list/submissions/2144366746

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
    ListNode* removeNodes(ListNode* head) {
        
        stack<ListNode*> st;
        while (head != NULL) {

            while (!st.empty() && st.top()->val < head->val) {
                st.pop();
            }

            st.push(head);
            head = head->next;
        }

        head = NULL;
        while (!st.empty()) {

            ListNode* node = st.top();

            if (!head) {
                head = node;
            }
            else {
                node->next = head;
                head = node;
            }
            st.pop();
        }
        return head;
    }
};