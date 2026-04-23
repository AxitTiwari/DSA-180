#include <iostream>
#include <set>

using namespace std;

int main() {

    /*
        set - ordered collection of unique elements.
    */

    set<int> s;

    s.insert(1);
    s.insert(9);
    s.insert(9);
    s.insert(9);
    s.insert(7);
    s.insert(7);
    s.insert(4);
    s.insert(8);

    for(auto i : s) {
        cout << i << endl;
    }
    cout << endl;

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);
    for(auto i : s) {
        cout << i << endl;
    }
    cout << endl;

    cout << "5 present or not -> " << s.count(5) << endl;
    return 0;
}