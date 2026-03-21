#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};

class Solution {
  private:
    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
  public:
    bool isPalindrome(Node *head) {
        //  code here
        
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        // 1 find middle
        Node* middle = findMiddle(head);
        
        // 2 reverse after middle
        Node* temp = middle->next;
        middle->next = reverse(temp);
        
        // compaire
        Node* head1 = head;
        Node* head2 = middle->next;
        while (head2) {
            if (head1->data != head2->data) {
                return false;
            }
            
            head1 = head1->next;
            head2 = head2->next;
        }
        
        // repeat step 2
        temp = middle->next;
        middle->next = reverse(temp);
        
        return true;
    }
};