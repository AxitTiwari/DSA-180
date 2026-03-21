#include <iostream>
#include <map>

void print(std::map <int, std::string> m) {
    for (auto i : m) {
        std::cout << i.first << " " << i.second << std::endl;
    } std::cout << std::endl;
}

int main() {

    std::map <int, std::string> m;
    
    // insertion
    m[1] = "I";
    m[3] = "Moon";
    m[2] = "Love";

    // insertion
    m.insert({5, "not Stars"});

    for (auto i : m) {
        std::cout << i.first << " " << i.second << std::endl;
    } std::cout << std::endl;

    std::cout << m.count(5);

    m.erase(5);
    print(m);

    auto it = m.find(2);
    for (auto i = it; i != m.end(); i++) {
        std::cout << (*i).first << " " << (*i).second << std::endl;
    } std::cout << std::endl;

    return 0;
}