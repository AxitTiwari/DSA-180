#include <iostream>
#include <queue>

int main() {

    // max heap
    std::priority_queue <int> maxi;

    // min head
    std::priority_queue <int, std::vector<int>, std::greater<int>> mini;

    maxi.push(1);
    maxi.push(9);
    maxi.push(5);
    maxi.push(10);

    while (!maxi.empty()) {
        std::cout << maxi.top() << " ";    // 10 9 5 1 
        maxi.pop();
    }

    std::cout << std::endl;

    mini.push(1);
    mini.push(9);
    mini.push(5);
    mini.push(10);

    while (!mini.empty()) {
        std::cout << mini.top() << " ";  
        mini.pop();
    }

    return 0;
}