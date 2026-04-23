#include <iostream>

void print(int *p) {

    std::cout << "p : " << p << std::endl;
    std::cout << "*p: " << *p << std::endl;
}

void update(int *p) {

    p = p + 1;
    std::cout << "In update: " << p << std::endl;
}

int main() {

    int a = 5;
    int *p = &a;

    // print(&a);

    std::cout << "Before update: " << p << std::endl; // same
    update(p);
    std::cout << "After update: " << p << std::endl; // same



    return 0;
}