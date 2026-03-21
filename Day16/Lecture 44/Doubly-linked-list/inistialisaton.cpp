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

    Node* node = new Node(10);

    // std::cout << node->data << std::endl;
    print(node);

    std::cout << length(node) << std::endl;

    return 0;
}