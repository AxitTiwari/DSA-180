#include <iostream>

int main() {

    // pointer = variable that stores a memory address of another variable
    //           somethimes it's easier to work with an memory

    // & address of operator
    // * dereference operator

    std::string name = "Axit Tiwari";

    std::string *pName = &name;

    std::cout << pName << '\n';
    std::cout << *pName << '\n';

    return 0;
}