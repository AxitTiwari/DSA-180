#include <iostream>
#include <algorithm>

void reverse(std::string& str, int start, int end) {

    if (start > end) return;

    std::swap(str[start], str[end]);
    start++;
    end--;
    reverse(str, start, end);
}

int main() {

    std::string name = "axit";

    reverse(name, 0, name.length()-1);

    std::cout << name << std::endl;

    return 0;
}