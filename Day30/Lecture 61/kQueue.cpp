#include <bits/stdc++.h>

class kQueue {
private:
    int* arr;
    int* next;
    int* front;
    int* rear;
    int freeSpot;
    int size;
    int k;

public:
    kQueue(int size, int k) {

        this->size = size;
        this->k = k;

        arr = new int[size];

        // next points to next free space after current block (at strat, when queue is empty)
        // and points to next element after current element (when queue starts to filling)
        next = new int[size];
        for (int i = 0; i < size-1; i++) {
            next[i] = i+1;
        }
        next[size-1] = -1;

        // -----fill front and rear array with -1------
        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        // first place to insert any element to any nth queue;
        freeSpot = 0;
    }

    void enqueue(int data, int qn) {

        if (freeSpot == -1) {
            std::cout << "overflow\n";
            return;
        }

        // find the index to insert on
        int index = freeSpot;

        // update the value of freeSpot
        // next[index] -> is pointing to the next memory block , which is empty, otherwise -1 for full
        freeSpot = next[index];

        // check if we are inserting first element to particular queue
        if (front[qn-1] == -1) {
            front[qn-1] = index;
        }
        else {
            // point previous element of nth queue with this new element to keep track of elements
            next[rear[qn-1]] = index;
        }

        // value if being ocuupied then make it filled
        next[index] = -1;

        // update rear
        rear[qn-1] = index;

        // push element
        arr[index] = data;
    }

    int dequeue(int qn) {

        if (front[qn-1] == -1) {
            std::cout << "underflow\n";
            return -1;
        }

        // find index to pop
        int index = front[qn-1];

        // move front
        front[qn-1] = next[index];

        // connect freeSpot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    void print(int qn) {

        std::cout << "printing " << qn << "th queue\n";

        int index = front[qn-1];

        while (index != -1) {
            std::cout << arr[index] << " ";
            index = next[index];
        }
        std::cout << std::endl;
    }
};

int main() {

    kQueue q(10, 3);

    q.enqueue(5, 1);
    q.enqueue(9, 2);
    q.enqueue(15, 1);
    q.enqueue(8, 3);

    q.print(1);
    q.print(2);
    q.print(3);

    std::cout << "after pop: \n";
    std::cout << "poped element: " << q.dequeue(1) << std::endl;
    q.print(1);

    return 0;
}

