#include <iostream>
using namespace std;
int main() {
/*
    For loop
    Syntax-
    for(initialization, condition(single/multiple), increment/decrement)

    initialization -> not mendatory --> put only ";"
    condition -> not mendatory --> put only ";"
    increment -> not neccessary --> put only ";"

    for(;;) <-- can we write like this?  <-- yes, infinite loop

    for(; i <= n; )  {
        i++;
    }

    for loop flow -
    first -> initialization(on time only in entire loop) --> condition -> (if true) -> body -> updation -> condition -> body -> updation -> condion .... and so on
*/
    int n, i;
    cout << "enter the value of n : ";
    cin >> n;
    cout << "Printing count from 1 to n" << endl;
    for(i = 1; i <= n; i++) {
        cout << i;
    }

    // for(;;) {
    //     cout << "ok" << endl;
    // }

    i = 1;
    for(; ; ) {   // <- do not know when to stop --> infinite loop
        if(i <= n) {
            cout << i << endl;
        }
        else
            break; // <-- Stoping condition (break from nearest loop)
        i++;
    }

    // 2 conditions & 2 updations
    for(int a = 0, b = 1, c = 2; a >= 0 && b >= 1 || c >= 2; a--, b--, c--) {
        cout << a << " " << b << " " << c << endl;
    }


}