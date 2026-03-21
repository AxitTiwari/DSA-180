#include <iostream>
#include <map>

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
public:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    bool detectLoop() {

        if (head == NULL) {
            return false;
        }

        std::map<Node*, bool> visited;

        Node* curr = head;
        while (curr) {

            // cycle detected
            if (visited[curr] == true) {
                return true;
            }

            visited[curr] = true;
            curr = curr->next;
        }
        return false;
    }

    bool isCircular() {

        if (head == NULL) return true;

        Node* curr = head->next;

        while (curr && curr != head) curr = curr->next;

        if (curr == NULL) return false;
        else return true;
    }

    void deleteAtBegin() {

        if (head == NULL) {
            std::cout << "list is null\n";
            return;
        }

        Node* node_to_delete = head;
        if (head == tail) {
            head = tail = NULL;
        }
        else {
            head = head->next;
            tail->next = head;
        }
        delete node_to_delete;
    }

    void deleteAtEnd() {

        // std::cout << "start\n";
        Node* current = head;

        do {
            // 1 2 3 4 NULL
            current = current->next;
        } while (current->next != head && current->next->next != head);

        // std::cout << "after loop\n";
        Node* node_to_delete = current->next;

        current->next = head;

        delete node_to_delete;
        // std::cout << "end\n";
    }

    void deleteAtValue(int value) {

        if (head == NULL) {
            std::cout << "list is null\n";
        }

        Node* temp = head;
        Node* prev = NULL;

        // 1 2 3 4
        while (temp->next != head && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp->next == head && temp->data != value) {
            std::cout << "No data found\n";
            return;
        }

        if (temp == head) {
            deleteAtBegin();
            return;
        }

        if (temp == tail) {
            deleteAtEnd();
            return;
        }

        // 1 2 3 4
        Node* node_to_delete = temp;
        prev->next = temp->next;

        delete node_to_delete;
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

    // -------create a list with cycle--------
    CircularLinkedList cList;

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);

    cList.head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node4;

    // going to print a infinite list , you can check that
    // cList.print();
    // ----------------------------------------
    bool isCycle = cList.detectLoop();

    if (isCycle) {
        std::cout << "cycle" << std::endl;
    }
    else {
        std::cout << "no cycle" << std::endl;

    }
    
    return 0;
}