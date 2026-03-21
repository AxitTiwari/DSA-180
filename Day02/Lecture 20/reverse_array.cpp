#include <iostream>
#include <vector>

std::vector <int> reverse(std::vector <int> v) {

    int start = 0, end = v.size()-1;

    while (start <= end) {
        std::swap(v[start], v[end]);
        start++;
        end--;
    }

    return v;

}

void print(std::vector <int> v) {

    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::vector <int> v = {1, 3, 4, 5, 6};
    print(v);
    v = reverse(v);
    print(v);
    
    return 0;
}