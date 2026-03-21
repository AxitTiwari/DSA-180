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

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        this->head = nullptr;
    }

    // by counting number of 0's, 1's and 2's
    Node* sortList(){

        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;

        Node* temp = head;
        while (temp) {

            if (temp->data == 0)
                zeroCount++;
            else if (temp->data == 1)
                oneCount++;
            else
                twoCount++;
            
            temp = temp->next;
        }

        temp = head;
        while (temp) {

            if (zeroCount != 0) {
                temp->data = 0;
                zeroCount--;
            }
            else if (oneCount != 0) {
                temp->data = 1;
                oneCount--;
            }
            else {
                if (twoCount != 0) {
                    temp->data = 2;
                    twoCount--;
                }
            }
            temp = temp->next;
        }
        return head;
    }

    void removeDuplicateUsingMap() {

        if (head == NULL || head->next == NULL) return;

        std::map<int, bool> visited;

        visited[head->data] = true;
        
        Node* curr = head->next;
        Node* prev = head;
        while (curr) {

            if (visited[curr->data] == true) {

                Node* node_to_delete = curr;
                prev->next = node_to_delete->next;
                curr = curr->next;
                delete node_to_delete;
            }
            else {
                visited[curr->data] = true;
                prev = curr;
                curr = curr->next;
            }
        }
    }

    void uniqueUnsortedList() {

        // std::cout << "start\n";
        if (head == NULL) {
            return;
        }

        // std::cout << "before loop\n";
        Node* curr = head;
        while (curr->next) {

            Node* prev = curr;
            Node* next = curr->next;
            // std::cout << "before inner loop\n";
            while (next->next) {

                if (curr->data == next->data) {
                    // delete it
                    prev->next = next->next;
                    delete next;
                    break;
                }
                next = next->next;
            }
            // std::cout << "after inner loop\n";
            curr = curr->next;
        }
        // std::cout << "end\n";
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
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(0);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);

    list.print();
    std::cout << "---------------------clearing.....--------------------\n";

    return 0;
}