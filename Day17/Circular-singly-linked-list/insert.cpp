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

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }

        Node* curr = head;
        do{
            curr = curr->next;
        } while (curr != tail);

        // 1 2 3 4 NULL
        curr->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    void insertAtBegin(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    void insertAtPosition(int position, int data) {

        if (position < 0 && position > length()) {
            std::cout << "Invalid Position\n";
            return;
        }

        if (position == 1) {
            insertAtBegin(data);
            return;
        }

        if (position == length()) {
            insertAtEnd(data);
            return;
        }

        // 1 2 3 4 NULL
        Node* curr = head;
        do {
            curr = curr->next;
            position--;
        } while (curr != head && position != 2);

        Node* node_to_insert = new Node(data);
        node_to_insert->next = curr->next;
        curr->next = node_to_insert;
    }

    void print() {

        if (head == NULL) {
            std::cout << "NULL" << std::endl;
            return;
        }

        Node* temp = head;
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        std::cout << std::endl;
    }

    int length() {

        if (head == NULL) return 0;

        Node* temp = head;
        int cnt = 0;
        do {
            cnt++;
            temp = temp->next;
        } while (temp != head);
        return cnt;
    }
};

int main() {

    CircularLinkedList cList;

    cList.insertAtBegin(10);
    cList.insertAtBegin(20);
    cList.insertAtBegin(30);
    cList.insertAtEnd(40);
    cList.insertAtPosition(3, 200);
    cList.insertAtPosition(2, 200);
    cList.print();

    return 0;
}