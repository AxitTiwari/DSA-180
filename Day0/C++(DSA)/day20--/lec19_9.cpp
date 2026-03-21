#include <iostream>
#include <map>

using namespace std;

int main() { 
    /*
        map - Stores elements as key-value pairs ({key, value})
    */

    // create a map
    map<int, string> m;

    // insert values
    m[1] = "axit";
    m[13] = "jasspreet";
    m[2] = "suresh";

    m.insert({5, "Riya"});

    // print
    cout << "Before erase" << endl;
    for(auto i : m) {
        cout << i.first << " " << i.second << endl;
    }

    // find a key
    cout << "Finding 13 -> " << m.count(13) << endl;

    // remove key:value 
    m.erase(13);

    cout << "After erase" << endl;
    for(auto i : m) {
        cout << i.first << " " << i.second << endl;
    }

    cout << "Finding 13 -> " << m.count(13) << endl;

    // find 
    auto it = m.find(5);

    m[6] = "unknown";

    for(auto i = it; i != m.end(); i++) {
        cout << (*i).first << endl;
    }

    return 0;
}