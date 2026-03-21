#include <iostream>
#include <list>

int main() {

    std::list <int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_front(3);

    for (int i : myList) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    myList.erase(myList.begin());

    for (int i : myList) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    std::cout << myList.size() << std::endl;

    return 0;
}