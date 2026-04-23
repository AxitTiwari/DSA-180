#include <iostream>
#include <stack>

std::string reverse(std::string str) {

    std::stack<char> s;

    for (int ch : str) {
        s.push(ch);
    }

    std::string ans;
    while (!s.empty()) {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    return ans;
}

int main() {

    std::string str = "axit";

    str = reverse(str);

    std::cout << str << std::endl;
    return 0;
}