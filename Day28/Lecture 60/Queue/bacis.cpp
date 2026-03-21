#include <iostream>
#include <queue>

int main() {

    // -------creation of queue----------
    std::queue<int> q;

    // ------insertion of elements-------
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    // -------front element---------
    std::cout << "front element: " << q.front() << std::endl;

    // ---------size-----------
    std::cout << "size: " << q.size() << std::endl;

    // --------remove elements-------
    q.pop();
    q.pop();

    std::cout << "front element: " << q.front() << std::endl;
    std::cout << "size: " << q.size() << std::endl;

    return 0;
}