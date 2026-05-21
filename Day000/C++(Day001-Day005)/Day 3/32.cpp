#include <iostream>

int main() {

    int *pNum = NULL;

    pNum = new int;

    *pNum = 21;

    std::cout << pNum << std::endl;
    std::cout << *pNum << std::endl;

    delete pNum;

    return 0;
}