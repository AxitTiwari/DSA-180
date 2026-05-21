#include <iostream>
using namespace std;
int main() {
/*
    variables & scopes

*/
    int a = 3; // this is initialised globally for entire main() program
    cout << a << endl;
    if(true) {
        int a = 5; //<-- this 'a' is just initialised for this if block
        int b = 5;
        cout << a << endl;
    }
    int b = 1;
    cout << b << endl; // <-- 1 is output not 5

    int i = 7;
    for(int i = 1; i <= 8; i++) {
        //hi will be printed 8 times not just once.
        cout << "hi" << endl;
    }

}