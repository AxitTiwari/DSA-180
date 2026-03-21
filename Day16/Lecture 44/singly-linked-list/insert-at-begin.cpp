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

    void insertAtBegin(LinkedList*& head, int data) {
        LinkedList* newNode = new LinkedList(data);
        newNode->next = head;
        head = newNode;
    }

    void print(LinkedList*& head) {

        LinkedList* temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {

    LinkedList* head = new LinkedList(1);

    (*head).insertAtBegin(head, 2);
    (*head).insertAtBegin(head, 3);
    (*head).insertAtBegin(head, 4);

    (*head).print(head);

    return 0;
}