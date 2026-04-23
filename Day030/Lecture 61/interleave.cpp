#include <iostream>
#include <stack>
#include <queue>

// using stack
void interleave(std::queue<int>& q, int size) {

    // #1. first half of the queue -> stack
    std::stack<int> s;

    int firstHalf = size / 2;

    while (firstHalf--) {

        int val = q.front();
        q.pop();

        s.push(val);
    }

    // #2. stack -> queue;
    while (!s.empty()) {
        int val = s.top();
        s.pop();

        q.push(val);
    }

    // #3. first half of the queue -> queue

    firstHalf = size / 2;

    while (firstHalf--) {

        int val = q.front();
        q.pop();

        q.push(val);
    }

    // #4. first half of the queue -> stack
    firstHalf = size / 2;

    while (firstHalf--) {

        int val = q.front();
        q.pop();

        s.push(val);
    }

    // #5. pop one from stack -> queue, pop one from queue -> push into queue

    while (!s.empty()) {

        int val = s.top();
        s.pop();

        q.push(val);

        val = q.front();
        q.push(val);
        q.pop();
    }
}

void print(std::queue<int> q) {

    while (!q.empty()) {

        std::cout << q.front() << " ";
        q.pop();
    }

    std::cout << std::endl;
}

int main() {

    std::queue<int> q;

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    std::cout << "queue before \n";
    print(q);

    interleave(q, 8);

    std::cout << "queue after interleave by half:\n";
    print(q);

    return 0;
}