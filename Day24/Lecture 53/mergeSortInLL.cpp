#include <bits/stdc++.h>
using namespace std;

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };

node* findMid(node* head) {

    if (head == NULL) return head;

    node* slow = head;
    node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right) {

    if (left == NULL) return right;

    if (right == NULL) return left;

    node* ans = new node(-1);
    node* temp = ans;

    while (left && right) {

        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right) {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

node* mergeSort(node *head) {
    // Write your code here.

    // 1 2 3 4 NULL
    if (head == NULL || head->next == NULL) return head;

    // mid -> 2
    // left -> 1 2 3 4 NULL
    // right -> 3 -> 4 NULL
    // 1 2 NULL, 3 4 NULL
    node* mid = findMid(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node* result = merge(left, right);
    return result;
}
