#include <iostream>
#include <queue>

int main() {

    std::queue <std::string> q;

    q.push("I");
    q.push("Love");
    q.push("Moon");

    std::cout << q.size() << std::endl;

    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
    return 0;
}