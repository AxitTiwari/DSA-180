// https://leetcode.com/problems/linked-list-cycle/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* cur = head;
        
        unordered_set<ListNode*> seen;
        while (cur) {

            if (seen.find(cur) != seen.end()) {
                return true;
            }

            seen.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};