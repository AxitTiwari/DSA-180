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

void insertAtBegin(Node*& head, int data) {

    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void print(Node* head) {

    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

int length(Node* head) {

    Node* temp = head;
    int cnt = 0;
    while (temp) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main() {

    Node* node = new Node(1);
    Node* head = node;

    insertAtBegin(head, 2);

    // std::cout << node->data << std::endl;
    print(head);

    std::cout << std::endl << length(head) << std::endl;

    return 0;
}