#include <iostream>
#include <stack>

int main() {

    std::stack <std::string> s;

    s.push("I");
    s.push("Love");
    s.push("Moon");

    std::cout << s.size() <<std::endl;
    
    std::cout <<s.top() << std::endl;

    while (!s.empty()) {
        std::cout <<s.top() << " ";
        s.pop();
    }

    std::cout << std::endl;

    std::cout << s.empty() << std::endl;

    return 0;
}