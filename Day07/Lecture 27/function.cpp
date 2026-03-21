#include <iostream>

void update(int ***p2) {

    // change hoga
    *p2 = *p2 + 1; 
}

void update1(int **p2) {

    // change nahi hoga
    p2 = p2 + 1; 
}

void update2(int **p2) {

    // change hoga
    *p2 = *p2 + 1; 
}

void update3(int **p2) {

    // change hoga
    **p2 = **p2 + 1; 
}

int main() {

    int i = 5;
    int* p = &i;
    int** p2 = &p;

    std::cout << "--------------Before---------------" << std::endl;
    std::cout << "i: " << i << std::endl;
    std::cout << "p: " << p << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    // update(&p2);
    // update1(p2);
    // update2(p2);
    update3(p2);

    std::cout << "--------------After---------------" << std::endl;
    std::cout << "i: " << i << std::endl;
    std::cout << "p: " << p << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    return 0;
}