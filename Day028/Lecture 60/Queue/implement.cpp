#include <bits/stdc++.h> 
using namespace std;

class Queue {
public:

    int* arr;
    int qFront;
    int rear;
    int size;

    Queue() {
        size = 100001;
        arr = new int[size];
        qFront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        
        if (qFront == rear) return true;
        return false;
    }

    void enqueue(int data) {
        
        if (rear == size) {
            return;
        }
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        
        if (isEmpty()) {
            qFront = rear = 0;
            return -1;
        }
        else {
            int ans = arr[qFront];
            arr[qFront] = -1;
            qFront = qFront + 1;
            return ans;
        }
    }

    int front() {
        
        if (isEmpty()) {
            return -1;
        }
        return arr[qFront];
    }
};