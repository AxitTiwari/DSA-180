#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  private:
    void insertAtEnd(Node*& head, Node*& tail, int data) {
        
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    
  public:
    Node* cloneLinkedList(Node* head) {
        // code here
        
        Node* originalNode = head;
        
        // --------- #1. clone the LL using next poinert ---------
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        while (originalNode) {
            insertAtEnd(cloneHead, cloneTail, originalNode->data);
            originalNode = originalNode->next;
        }
        // -------------------------------------------------------
        
        // ----------- #2. clone nodes -> add in between original list --------------
        originalNode = head;
        Node* clone = cloneHead;

        while (originalNode) {

            Node* next = originalNode->next;
            originalNode->next = clone;
            originalNode = next;

            next = clone->next;
            clone->next = originalNode;
            clone = next;
        }
        // ---------------------------------------------------------------------------

        // ------------- #3. set random pointer ---------------------
        originalNode = head;
        clone = cloneHead;

        while (originalNode) {
            
            if (originalNode->random) {
                originalNode->next->random = originalNode->random->next;
            }
            else {
                originalNode->next->random = NULL;
            }
            originalNode = originalNode->next->next;
        }
        // -----------------------------------------------------------

        // ----------- # 4. revert changes in step 2 -----------------
        originalNode = head;
        clone = cloneHead;

        while (originalNode && clone ){
            originalNode->next =
            originalNode->next? originalNode->next->next : originalNode->next;
         
            clone->next = clone->next ? clone->next->next : clone->next;
            originalNode = originalNode->next;
            clone = clone->next;
        }

        // -----------------------------------------------------------
        
        // return cloned list
        return cloneHead;
    }

};