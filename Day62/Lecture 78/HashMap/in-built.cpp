#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<string, int> m;

    // Insertion

    // 1.
    pair<string, int> p = make_pair("Axit", 19);
    m.insert(p);

    // 2
    pair<string, int> p2("avni", 18);
    m.insert(p2);

    // 3
    // first time creating of the key
    m["moon"] = 13;

    // value rewrite
    // second time creating of the key, it will update the value of the key
    m["moon"] = m["moon"] + 2;

    // searching
    cout << m["avni"] << endl;
    cout << m.at("Axit") << endl;

    // size
    cout << m.size() << endl;

    // searching
    cout << m.count("moon") << endl;

    return 0;
}