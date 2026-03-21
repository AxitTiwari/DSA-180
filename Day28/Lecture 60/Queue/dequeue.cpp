#include <iostream>
#include <queue>

int main() {

    // -------creation of dueue----------
    std::deque<int> d;

    // ------insertion of elements-------
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);

    // -------front element---------
    std::cout << "front element: " << d.front() << std::endl;

    // ---------size-----------
    std::cout << "size: " << d.size() << std::endl;

    // --------remove elements-------
    d.pop_front();
    d.pop_back();

    std::cout << "front element: " << d.front() << std::endl;
    std::cout << "back element: " << d.back() << std::endl;
    std::cout << "size: " << d.size() << std::endl;

    return 0;
}