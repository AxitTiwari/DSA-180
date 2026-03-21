#include <iostream>

class LinkedList {
public:
    int data;
    LinkedList* next;

    LinkedList() {} 

    LinkedList(int data) {
        this->data = data;
        this->next = NULL;
    }

     void insertAtEnd(LinkedList*& tail, int data) {
        LinkedList* newNode = new LinkedList(data);
        tail->next = newNode;
        tail = newNode;
    }

    void insertAtBegin(LinkedList*& head, int data) {
        LinkedList* newNode = new LinkedList(data);
        newNode->next = head;
        head = newNode;
    }

    // ----------------------insert at a position------------------------
    void insertAtPostion(LinkedList*& head, LinkedList*& tail, int data, int pos) {
        
        if (pos < 0) {
            std::cout << "Invalid position\n";
            return;
        }

        // first node
        if (pos == 1) {
            insertAtBegin(head, data);
            return;
        }

        // ---------move a pointer to the previos node of desired index--------------
        LinkedList* current = head;
        LinkedList* prev = NULL;
        while (current && pos != 1) {
            prev = current;
            current = current->next;
            pos--;
        }
        // --------------------------------------------------------------------------

        // at last postion or beyond that
        if (current == NULL) {
            insertAtEnd(tail, data);
            return;
        }

        // -----create a memory & put it in desired position-------
        LinkedList* newNode = new LinkedList(data);

        newNode->next = prev->next;
        prev->next = newNode;
        // ---------------------------------------------------------
    }
    // -----------------------------------------------------------------------

    void print(LinkedList*& head) {

        LinkedList* temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {

    LinkedList* head = new LinkedList(1);

    LinkedList* tail = head;

    (*head).insertAtEnd(tail, 2);
    (*head).insertAtEnd(tail, 3);
    (*head).insertAtEnd(tail, 4);

    (*head).print(head);

    (*head).insertAtPostion(head, tail, 50, 1);
    (*head).insertAtPostion(head, tail, 100, 3);
    (*head).insertAtPostion(head, tail, 200, 10);

    (*head).print(head);

    return 0;
}