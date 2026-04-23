#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node (int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        this->head = nullptr;
    }

    void deleteAtBegin() {

        Node* node_to_delete = head;
        head = head->next;

        // memory is created in heap, so we have to free it manually
        delete node_to_delete;
    }

    void deleteAtEnd() {

        Node* current = head;

        // move the current pointer to the last 2nd node
        while (current->next && current->next->next) {
            current = current->next;
        }

        Node* node_to_delete = current->next;

        current->next = NULL;

        delete node_to_delete;
    }

    void deleteAtPosition(int position) {

        // position is incorrect
        if (position < 0) {
            std::cout << "not a valid position\n";
            return;
        }

        // START is target
        if (position == 1) {
            deleteAtBegin();
            return;
        }

        Node* current = head;
        Node* prev = NULL;
        while (current && position != 1) {
            prev = current;
            current = current->next;
            position--;
        }

        // at last postion or beyond that
        if (current == NULL) {
            deleteAtEnd();
            return;
        }

        Node* node_to_delete = current;
        prev->next = current->next;

        delete node_to_delete;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);

        Node* curr = head;
        while (curr->next) curr = curr->next;

        // 1 2 3 4 NULL
        curr->next = newNode;
    }

    void insertAtBegin(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void print() {

        Node* temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {

    LinkedList list;

    list.insertAtBegin(10);
    list.insertAtEnd(20);
    list.print();

    return 0;
}