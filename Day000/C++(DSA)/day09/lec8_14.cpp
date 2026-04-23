#include <iostream>
using namespace std;

void dummy(int n) {

    n++;
    cout << "n is " << n << endl;

}

int main() {
/*
    pass by value 

    main() -> n - dummy() <- n - copy
*/
    int n;
    cin >> n;

    dummy(n);

    cout << "n is " << n << endl;

    return 0;
}