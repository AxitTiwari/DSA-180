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
        
        // ----------- #2. create mapping --------------
        unordered_map<Node*, Node*> oldToNew;
        originalNode = head;
        Node* cloneNode = cloneHead;
        
        // map origianl list node with cloned list node
        while (originalNode) {
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        // set the random pointer of cloned list
        originalNode = head;
        cloneNode = cloneHead;
        
        while (cloneNode) {
            cloneNode->random = oldToNew[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        // ---------------------------------------------
        
        // return cloned list
        return cloneHead;
    }
};