#include <iostream>

typedef std::string text_t;

using number_t = int;
int main() {

    // typedef keyword

    text_t name = "Bro";
    number_t age = 21;

    std::cout << name << age;
    return 0;
}