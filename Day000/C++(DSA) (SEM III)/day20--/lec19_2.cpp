#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    /*
        vector - dynamic datastrcture
    */

    // create your vector
    vector<int>v;

    // capacity
    cout << "Capacity-> " << v.capacity() << endl;

    // input element
    v.push_back(1);
    cout << "Capacity-> " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity-> " << v.capacity() << endl;

    v.push_back(3);
    cout << "Capacity-> " << v.capacity() << endl;
    
    // check the size
    cout << "Size-> " << v.size() << endl;

    // first and last element
    cout << "front " << v.front() << endl;
    cout << "back " << v.back() << endl;

    // print elements
    cout << "before pop ";
    for(int i:v) {
        cout << i << " ";
    }
    cout << endl;

    // pop
    v.pop_back();
    cout << "after pop ";
    for(int i:v) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Size-> " << v.size() << endl;
    cout << "Capacity-> " << v.capacity() << endl;

    // clear
    cout << "After clear" << endl;
    v.clear();
    cout << "Size-> " << v.size() << endl;
    cout << "Capacity-> " << v.capacity() << endl;

    // create the vector with size
    vector<int>a(5); 

    // by default all the values are initialised by 0.
    cout << "vector a: ";
    for(int i:a) {
        cout << i << " ";
    }
    cout << endl;

    // create a vector 'last' containg all the elements of vector 'a'
    vector<int>last(a);
    cout << "vector last: ";
    for(int i:a) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}