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

    void uniqueSortedList() {

        if (head == NULL) {
            return;
        }

        Node* curr = head;
        while (curr->next) {
            if (curr->data == curr->next->data) {
                Node* node_to_delete = curr->next;
                curr->next = node_to_delete->next;
                delete(node_to_delete);
                node_to_delete = NULL;
            }
            else {
                curr = curr->next;
            }
        }
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

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* tail = head;
        while (tail->next) tail = tail->next;

        // 1 2 3 4 NULL
        tail->next = newNode;
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

    std::cout << "--------------processing....--------------------\n";


    // ----------------create a LL------------------
    std::cout << "creating linked list..\n";
    LinkedList list;
    list.insertAtEnd(1);
    std::cout << "creating linked list..\n";
    list.insertAtEnd(2);
    std::cout << "creating linked list..\n";
    list.insertAtEnd(3);
    std::cout << "creating linked list..\n";
    list.insertAtEnd(3);
    std::cout << "creating linked list..\n";
    list.insertAtEnd(4);
    std::cout << "CREATED\n";
    list.print();

    std::cout << "Applying function to linked list...\n";
    list.uniqueSortedList();
    std::cout << "SORTED linked list -> duplicated REMOVED!\n";
    list.print();
    std::cout << "---------------------clearing.....--------------------\n";

    return 0;
}