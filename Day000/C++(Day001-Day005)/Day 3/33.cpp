#include <iostream>
template <typename T, typename U>

auto max(T a, U b) {
    return (a > b) ? a : b;
}

int main() {

    // function template = describes what a function looks like.
    //                     can be used to generate as many overloaded functions
    //                     as needed, each using different data types

    std::cout << max(1.1, 2.2) << '\n';
    std::cout << max(1, 2) << '\n';
    std::cout << max('A', 'B') << '\n';
    std::cout << max(1.5, 0) << '\n';
    return 0;
}