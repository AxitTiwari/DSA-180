#include <iostream>
using namespace std;
int main() {
    //sum of 1 to N numbers.
    int N, i, sum;
    cout << "Enter the number N : " ;
    cin >> N;
    sum = 0;
    i = 1;
    while(i <= N) {
        sum += i;
        i++;
    }
    cout << "sum of 1 to N numbers is : " << sum << endl;
    return 0;    
}