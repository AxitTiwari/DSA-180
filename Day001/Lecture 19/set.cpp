#include <iostream>
#include <set>

void print(std::set <int> s) {
    for (auto i : s) {
        std::cout << i << " "; // 1 5 9 
    }
    std::cout << std::endl;
}

int main() {

    std::set <int> s;

    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(1);
    s.insert(9);

    for (auto i : s) {
        std::cout << i << " "; // 1 5 9 
    }
    std::cout << std::endl;

    std::set <int>::iterator it = s.begin();
    it++;
    s.erase(it);

    print(s);  // 1 9 

    std::cout << s.count(9) << std::endl; // 1

    std::set <int>::iterator itr = s.find(9);
    for (auto i = itr; i != s.end(); i++) {
        std::cout << *i << " "; //  9 
    }
    std::cout << std::endl;

    return 0;
}