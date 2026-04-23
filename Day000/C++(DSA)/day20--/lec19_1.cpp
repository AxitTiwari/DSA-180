#include <iostream>
#include <array>

using namespace std;

int main() {
    /*
        STL
        1. stl array - static data structure
    */

    int normal_array[] = {1, 2, 3, 4};
    array<int, 4>stl_array = {1, 2, 3, 4};

    // calculate size
    int size = stl_array.size();

    // print elements
    for(int i = 0; i < size; i++) {
        cout << stl_array[i] <<endl;
    }

    // access specific element in the array
    cout << "Element at index 2 is " << stl_array.at(2) << endl;

    // Empty
    cout << "Empty or Not-> " << stl_array.empty() << endl;

    // First and last element
    cout << "First element " << stl_array.front() << endl;
    cout << "Last element " << stl_array.back() << endl;

    return 0;
}