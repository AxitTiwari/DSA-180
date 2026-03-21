#include <iostream>

class Stack {
private:
    int top;
    int* arr;
    int size;

public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data) {
        if (top < size) {
            arr[++top] = data;
        }
        else {
            std::cout << "stack overflow\n";
        }
    }

    void pop() {

        if (top >= 0) {
            top--;
        }
        else {
            std::cout << "stack underflow\n";
        }
    }

    int peak() {
        if (top >= 0) return arr[top];
        else {
            std::cout << "stack is empty\n";
        }
    }

    bool empty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

};

int main() {

    Stack s(10);

    s.push(1);
    s.push(3);

    std::cout << s.empty() << std::endl;

    std::cout << s.peak() << std::endl;

    return 0;
}