#include <iostream>

int main() {

    int value = 8;
    int* pValue = &value;
    int** ppValue = &pValue;

    std::cout << "Address of value: " << &value << std::endl;
    std::cout << "pValue: " << pValue << std::endl;
    std::cout << "*ppValue: " << *ppValue << std::endl;
    std::cout << "*pValue: " << *pValue << std::endl;
    std::cout << "**ppValue: " << **ppValue << std::endl;

    return 0;
}