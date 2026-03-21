#include <bits/stdc++.h>

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

Node<int>* merge(Node<int>* first, Node<int>* second) {

    if (first->next == NULL) {
        first->next = second;
        return first;
    }

    Node<int>* firstCurr = first;
    Node<int>* firstNext = firstCurr->next;
    Node<int>* secondCurr = second;

    while (firstNext && secondCurr) {

        // 1 3 5 NULL
        // 2 4 6 NULL
        if ( (firstCurr->data <= secondCurr->data) && (secondCurr->data <= firstNext->data) ) {

            second = second->next;
            secondCurr->next = firstCurr->next;
            firstCurr->next = secondCurr;
            firstCurr = firstCurr->next;
            firstNext = firstCurr->next;
            secondCurr = second;
        }
        else {
            firstCurr = firstCurr->next;

            if (firstNext)
                firstNext = firstNext->next;

            if (firstNext == NULL) {
                firstCurr->next = secondCurr;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second){
    // Write your code here.

    if (first == NULL) {
        return second;
    }

    if (second == NULL) {
        return first;
    }

    if (first->data <= second->data) {
        return merge(first, second);
    }
    else {
        return merge(second, first);
    }
}
