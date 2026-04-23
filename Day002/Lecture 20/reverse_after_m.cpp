#include <iostream>
#include <vector>

std::vector <int> reverse(std::vector <int> v, int M) {

    int start = M+1, end = v.size()-1;

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
    int M = 2;
    print(v);
    v = reverse(v, M);
    print(v);
    
    return 0;
}