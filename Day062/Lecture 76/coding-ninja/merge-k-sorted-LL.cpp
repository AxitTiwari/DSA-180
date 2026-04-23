#include <bits/stdc++.h>    
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

#include <queue>
// #include <priority_queue>
class compare {
public:

    // compare two nodes by there data values
    bool operator()(Node* first, Node* second) {
        return first->data > second->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray) {
    // Write your code here.

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    int k = listArray.size();

    if (k == 0) return NULL;

    // first element of k lists
    for (int i = 0; i < k; i++) {
        if (listArray[i] != NULL) {
            minHeap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while (!minHeap.empty()) {

        Node* top = minHeap.top();
        minHeap.pop();

        if (top->next) {
            minHeap.push(top->next);
        }

        if (head == NULL) {
            head = top;
            tail = top;
        }
        else {
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
