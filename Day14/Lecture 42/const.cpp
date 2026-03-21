#include <iostream>

using namespace std;

class Student {
    int marks;

public:
    // constant member function (getter)
    int getMarks() const {
        return marks;
    }
};


int main() {

    int x = 10;

    cout << "Initial value of x: " << x << endl;

    x = x + 10;

    cout << "Value of x after modification: " << x << endl;

    const int y = 10;

    cout << "Initial value of y: " << y << endl;

    // assignment of read-only variable
    // y = y + 10;
    // cout << "Value of y after modification: " << y << endl;

    return 0;
}