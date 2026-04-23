#include <iostream>

class Node {
public:
    Node* prev;
    int data;
    Node* next;

    Node(int data) {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insertAtBegin(int data) {

        Node* newNode = new Node(data);

        // first node
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        // otherwise
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int data) {

        // no node
        if (head == NULL) {
            insertAtBegin(data);
            return;
        }

        // otherwise
        // 1 2 3 4 NULL
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtPosition(int data, int position) {

        // invalid
        if (position <= 0) {
            std::cout << "Invalid position\n";
            return;
        }

        // first positon
        if (position == 1) {
            insertAtBegin(data);
            return;
        }

        Node* current = head;
        while (current && position != 1) {
            current = current->next;
            position--;
        }

        // edge cases
        if (current == NULL) {
            std::cout << "Invalid position\n";
            return;
        }

        // last position
        if (current->next == NULL) {
            insertAtEnd(data);
            return;
        }

        Node* insertAfterNode = current->prev;
        // at specific position
        Node* node_to_insert = new Node(data);
        node_to_insert->prev = insertAfterNode;
        node_to_insert->next = insertAfterNode->next;
        insertAfterNode->next->prev = node_to_insert;
        insertAfterNode->next = node_to_insert;
    }

    void print() {

        Node* temp = head;
        std::cout << "NULL <- ";
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    int length() {

        Node* temp = head;
        int cnt = 0;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};

int main() {

    // --------create a doubly linked list------------
    DoublyLinkedList dList;

    dList.insertAtBegin(1);
    dList.insertAtBegin(2);
    dList.insertAtBegin(3);
    dList.insertAtEnd(4);
    dList.insertAtEnd(5);
    dList.insertAtEnd(6);

    dList.print();

    // insert at a specific position
    dList.insertAtPosition(100, 3);

    dList.print();

    // ------------------------------------------------

    return 0;
}