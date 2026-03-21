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

    // ----------------insert at end----------------
    void insertAtEnd(LinkedList*& tail, int data) {
        LinkedList* newNode = new LinkedList(data);
        tail->next = newNode;
        tail = newNode;
    }
    // ---------------------------------------------

    void insertAtBegin(LinkedList*& head, int data) {
        LinkedList* newNode = new LinkedList(data);
        newNode->next = head;
        head = newNode;
    }

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

    return 0;
}