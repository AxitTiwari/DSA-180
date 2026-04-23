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

    void print() {

        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
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

    // insert at the start
    dList.insertAtBegin(1);
    dList.insertAtBegin(2);
    dList.insertAtBegin(3);

    // insert at the end
    dList.insertAtEnd(4);
    dList.insertAtEnd(5);
    dList.insertAtEnd(6);

    // print the list
    dList.print();
    // ------------------------------------------------


    return 0;
}