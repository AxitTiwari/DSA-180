#include <iostream>
using namespace std;
int main() {
/*
    int n;
    cout << "enter the value of n ";
    cin >> n;
    //cout << "Value of n is: " << n << endl;
    if(n > 0) {
        cout << "n is positive" << endl;
    }
    else {
        cout << "n is -ve" << endl;
    }

    int a, b;
    cout << "Enter the value of 'a' and 'b' " << endl;
    cin >> a >> b;

    if(a > b) {
        cout << "a is greater" << endl;
    }
    if(b > a) {
        cout << "b is greater " << endl;
    }
    cout << "Value of a and b is: " << a << " " << b << endl;
    // cin do not read space , tab and enter . if needed to read then use ->
    // int c;
    // c = cin.get();
    // cout << "c is " << c << endl;
*/
    // +ve, -ve and zero
    int x;
    cout << "enter the value of x" << endl;
    cin >> x;
    if(x > 0) {
        cout << "x is +ve" << endl;
    }
    else {
        if(x < 0) {
            cout << "x is -ve" << endl;
        }
        else {
            cout << " x is zero" << endl;
        }
    }
    return 0;
}