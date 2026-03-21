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

    void deleteAtBegin(LinkedList*& head) {

        LinkedList* node_to_delete = head;
        head = head->next;

        // memory is created in heap, so we have to free it manually
        delete node_to_delete;
    }

    void deleteAtEnd(LinkedList*& head, LinkedList*& tail) {

        LinkedList* current = head;

        // move the current pointer to the last 2nd node
        while (current->next != tail) {
            current = current->next;
        }

        LinkedList* node_to_delete = tail;

        tail = current;
        tail->next = NULL;
        
        // memory is created in heap, so we have to free it manually
        delete node_to_delete;
    }

    void deleteAtPosition(LinkedList*& head, LinkedList*& tail, int position) {

        // position is incorrect
        if (position < 0) {
            std::cout << "not a valid position\n";
            return;
        }

        // START is target
        if (position == 1) {
            deleteAtBegin(head);
            return;
        }

        LinkedList* current = head;
        LinkedList* prev = NULL;
        while (current && position != 1) {
            prev = current;
            current = current->next;
            position--;
        }

        // at last postion or beyond that
        if (current == NULL) {
            deleteAtEnd(head, tail);
            return;
        }

        // 1 2 3 4 NULL
        LinkedList* node_to_delete = current;
        prev->next = current->next;

        delete node_to_delete;
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

    // --------------create a linked list----------------
    LinkedList* head = new LinkedList(1);
    LinkedList* tail = head;

    (*head).insertAtEnd(tail, 2);
    (*head).insertAtEnd(tail, 3);
    (*head).insertAtEnd(tail, 4);
    (*head).insertAtPostion(head, tail, 50, 1);
    (*head).insertAtPostion(head, tail, 100, 3);
    (*head).insertAtPostion(head, tail, 200, 10);

    (*head).print(head);
    // --------------------------------------------------
   
    // delete at START
    (*head).deleteAtBegin(head);
    (*head).print(head);

    // delete at END
    (*head).deleteAtEnd(head, tail);
    (*head).print(head);

    // delete at specific position
    (*head).deleteAtPosition(head, tail, 1);
    (*head).print(head);

    (*head).deleteAtPosition(head, tail, 3);
    (*head).print(head);

    (*head).deleteAtPosition(head, tail, 10);
    (*head).print(head);

    return 0;
}