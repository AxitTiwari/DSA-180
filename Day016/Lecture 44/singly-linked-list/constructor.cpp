#include <iostream>

class Node {
public:
    int data;
    Node* next;

    // ------CONSTRUCTOR------
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    // -----------------------
};

int main() {

    Node* node = new Node(10);

    std::cout << node->data << " " << node->next << std::endl;

    // ----------------my doughts--------------------
/*
    std::cout << "address of node                   : " << &node << std::endl;
    std::cout << "value of node(address inside node): " << node << std::endl;
    // std::cout << "dereference the node: " << *node << std::endl;
    std::cout << "address of node->data             :" << &(node->data) << std::endl;
    std::cout << "address of node->next             : " << &(node->next) << std::endl;
*/
    // ----------------------------------------------

    return 0;
}