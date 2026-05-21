#include <iostream>
#include <list>

using namespace std;

int main() {

    /*
        list - random access -> ❌
    */

    // create the list
    list<int> l;

    // add element to front and back
    l.push_front(1);
    l.push_front(2);

    // print the list
    for(int i:l) {
        cout << i << " ";
    }
    cout << endl;

    // erase
    l.erase(l.begin());
    cout << "After erase ";
    for(int i:l) {
        cout << i << " ";
    }
    cout << endl;

}