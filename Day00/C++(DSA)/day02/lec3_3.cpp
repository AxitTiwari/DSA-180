#include <iostream>
using namespace std;
int main() {
    //prime number.
    int number, i, found;
    cout << "Enter the number : ";
    cin >> number;
    i = 2;
    found = 0;
    while(i <= number / 2) {
        //break if number divides by any number between range.
        if(number % i == 0) {
            cout << " number is not prime" << endl;
            found = 1;
            break;
        }
        i++;
    }
    if(!found) {
        cout << "number is prime number" << endl;
    }
    return 0;
}