#include <iostream>
#include <deque>

using namespace std;

int main() {

    /*
        Deque - dynamic data structure
    */

    // create a deque
    deque<int> d;

    // add elements in it in both directions
    d.push_front(1);
    d.push_back(2);
    d.push_front(3);

    // print the deque
    for(int i:d) {
        cout << i << " ";
    }
    cout << endl;

    // remove elements from deque from both front and end
    // d.pop_front();
    d.pop_back();
    for(int i:d) {
        cout << i << " ";
    }
    cout << endl;

    // random access of elements
    cout << "Element at index 1: " << d.at(1) << endl;

    // first and last element
    cout << "Front " << d.front() << endl;
    cout << "Back " << d.back() << endl;

    // empty
    cout << "Empty or not " << d.empty() << endl;

    // erase
    d.erase(d.begin(), d.begin()+1);
    cout << "After erase ";
    for(int i:d) {
        cout << i << " ";
    }
}