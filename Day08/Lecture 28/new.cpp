#include <iostream>

int main() {

    // --------------size-------------
    char ch = 'a';
    std::cout << sizeof(ch) << std::endl;

    char *pCh = &ch;
    std::cout << sizeof(pCh) << std::endl;
    // -------------------------------

    char* pNew = new char;
    std::cout << sizeof(pNew) << std::endl;

    return 0;
}