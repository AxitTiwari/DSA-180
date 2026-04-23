#include <iostream>

class Node {
public:

    // data
    int data;

    // pointer of node type
    Node* next;
};

int main() {

    std::cout << "-------------Creating a Node----------------\n";
    // creating a node dynamically
    Node* node = new Node;


    std::cout << "-------------Initialising node's value----------------\n";
    // initialising node's data
    node->data = 10;
    node->next = nullptr;

    std::cout << "-------------Printing node's data----------------";
    // printing node's data
    std::cout << node->data << " " << node->next << std::endl;

    // alternate way of printing
    std::cout << (*node).data << " " << (*node).next << std::endl;

/*
    // -------------my doughts----------------
    std::cout << "-------------my doughts----------------\n";
    Node obj;
    Node* head = &obj;
    obj.data = 10;
    obj.next = nullptr;
    std::cout << obj.data << " " << obj.next << std::endl;
    std::cout << head->data << " " << head->next << std::endl;
    // ----------------------------------------
*/

    return 0;
}