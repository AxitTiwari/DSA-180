#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    /*
        algorithms
    */

    // create a vector
    vector<int> v;

    // add elements in ascending order
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);

    // use binary search from range 'v.begin()' to 'v.end()' and search '6'
    cout << binary_search(v.begin(), v.end(), 6) << endl;

    cout << "lower bound " << lower_bound(v.begin(), v.end(), 3)-v.begin() << endl;
    cout << "upper bound " << upper_bound(v.begin(), v.end(), 3)-v.begin() << endl;

    int a = 5;
    int b = 9;

    // max, min
    cout << "max " << max(a, b) << endl;
    cout << "min " << min(a, b) << endl;

    // swap
    swap(a, b);

    cout << "a " << a << endl;
    cout << "b " << b << endl;

    // reverse
    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());
    cout << abcd << endl;

    // rotate vector
    rotate(v.begin(), v.begin()+1, v.end());
    cout << "after rotate " << endl;
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;

    // sorting
    sort(v.begin(), v.end());

    cout << "Ascending: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    return 0;

}