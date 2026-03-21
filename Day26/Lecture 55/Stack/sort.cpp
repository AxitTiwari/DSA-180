#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &s, int element) {

    if (s.empty() || s.top() < element) {
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();
    insertSorted(s, element);

    s.push(num);
}

void sort(stack<int> &stack) {
    // Write your code here

    if (stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();
    sort(stack);

    insertSorted(stack, num);
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

    std::cout << "after sorting the stack:\n";
    sort(s);

    print(s);
    return 0;
}