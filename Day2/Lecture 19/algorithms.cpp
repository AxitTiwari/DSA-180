#include <iostream>
#include <algorithm>
#include <vector>

int main() {

    std::vector <int> v = {1, 2, 2, 2, 3, 4, 5};

    // binary search
    std::cout << std::binary_search(v.begin(), v.end(), 4) << std::endl;

    // lower bound of 2
    std::cout << std::lower_bound(v.begin(), v.end(), 2) - v.begin() << std::endl; // 1

    // upper bound of 2
    std::cout << std::upper_bound(v.begin(), v.end(), 2) - v.begin() << std::endl; // 4

    // max/min
    int a = 2, b = 3;
    std::cout << std::max(a, b) << " " << std::min(a, b) << std::endl; // 3 2

    // swap 
    std::swap(a, b);
    std::cout << "a: " << a << std::endl;

    // Reverse
    std::string name = "axit";
    std::reverse(name.begin(), name.end());
    std::cout << "name: " << name << std::endl;

    // Rotate
    std::rotate(name.begin(), name.begin()+2, name.end());
    std::cout << name;

    return 0;
}