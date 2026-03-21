#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
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
    
    void insertAtTail(Node*& head, Node*& tail, int val) {
        
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    
    Node* add(Node* head1, Node* head2) {
        
        int carry = 0;
        Node* addHead = NULL;
        Node* addTail = NULL;
        
        // loop until both are not NULL
        while (head1 && head2) {
            
            int val1 = 0;
            if (head1 != NULL)
                val1 = head1 -> data;
                
            int val2 = 0;
            if (head2 !=NULL)
                val2 = head2 -> data;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum % 10;
             
            //create node and add in answer Linked List
            insertAtTail(addHead, addTail, digit);
            
            carry = sum/10;
            if(head1 != NULL)
                head1 = head1 -> next;
            
            if(head2 != NULL)
                head2 = head2 -> next;
        }
        return addHead;
    }
    
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        
        // trim 0 from start
        while (head1 && head1->data == 0) head1 = head1->next;
        while (head2 && head2->data == 0) head2 = head2->next;
        
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;
        
        // reverse both numbers first.
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        // add both numbers
        Node* addition = add(head1, head2);
        
        // reverse the resultant addition
        addition = reverse(addition);
        
        // return the required addition
        return addition;
    }
};