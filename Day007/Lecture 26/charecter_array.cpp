#include <iostream>

int main() {

    int a[5] = {1, 2, 3, 4, 5};

    std::cout << "a: " << a << std::endl;

    int *ptrArr = &a[0];

    // address of first element of integer array
    std::cout << "ptrArr: " << ptrArr << std::endl;

    char ch[6] = "abcde";

    // not an address
    std::cout << "ch: " << ch << std::endl; // -> prints entire content

    char *c = &ch[0];

    // not an address
    std::cout << "c: " << c << std::endl; 

    // ----------- for single char ----------------
    char temp = 'z';
    char *t = &temp;

    std::cout << "t: " << t << std::endl;

    return 0;
}