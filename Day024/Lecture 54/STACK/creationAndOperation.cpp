#include <iostream>
#include <stack>

int main() {

    std::stack<int> s;

    s.push(2);
    s.push(7);

    s.pop();

    std::cout << "top element: " << s.top() << " ";

    if (s.empty()) {
        std::cout << "stack is empty";
    }
    else {
        std::cout << "stack is not empty" << std::endl;
    }

    std::cout << "size of stack: " << s.size() << std::endl;
    return 0;
}