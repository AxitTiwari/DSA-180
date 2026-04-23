#include <iostream>
using namespace std;

int update(int a) {

    int ans = a * a;
    
    return ans;

}

int main() {

    int a = 14;

    // now we are returning the value and storing it in the variable 'a'.
    a = update(a);

    cout << a << endl;
}