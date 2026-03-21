#include <iostream>

int main() {

    int num = 5;

    std::cout << num << std::endl;

    std::cout << "Address of num: " << &num << std::endl;

    // ---------- Address of operator -----------
    int *ptr = &num; // initialisation
    std::cout << "Address of num: " << &num << std::endl;

    std::cout << "Value: " << *ptr << std::endl;
    // -------------------------------------------

    // ------------ Double data-type -------------
    double a = 10;
    double *p2 = &a;

    std::cout << "Address of a: " << p2 << std::endl;
    std::cout << "value: " << *p2 << std::endl;
    // -------------------------------------------

    // -----------copying a pointer --------------
    int number = 10;

    int *p = &number;
    int *q = p;

    std::cout << "p: " << p << std::endl;
    std::cout << "q: " << q << std::endl;
    // -------------------------------------------

// ----------- Pointer Arithematic -----------
    int i = 2;
    int *t = &i;
    
    std::cout << "before: " << *t << std::endl;
    *t = *t + 1;
    std::cout << "after: " << *t << std::endl;

    // increment memory space
    std::cout << "before: " << t << std::endl;
    t = t + 1;
    std::cout << "before: " << t << std::endl;
// -------------------------------------------

    return 0;
}