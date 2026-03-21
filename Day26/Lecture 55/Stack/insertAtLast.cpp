#include <iostream>
#include <stack>

void insertAtLast(std::stack<int>& s, int element) {

    if (s.empty()) {
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();
    insertAtLast(s, element);
    s.push(num);
}

void print(std::stack<int> s) {

    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
}

int main() {

    std::stack<int> s;

    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);

    std::cout << "initial stack:\n";
    print(s);

    std::cout << "after insertion at end:\n";
    insertAtLast(s, 9);

    print(s);
    return 0;
}