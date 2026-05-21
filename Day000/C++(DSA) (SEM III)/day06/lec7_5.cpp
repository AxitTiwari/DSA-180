#include <iostream>
using namespace std;
int main() {
/*
    power of two(231)
    eg. n = 16 = 2^4 -> valid number
    my logic 
    n = 6 != 2^x -> value of x as integer is not possible
    16 <-- 1. divide the number by 2 upto n does not become one . 
    16 -> 8 -> 4 -> 2 -> 1

    yes done
*/
    int n, found = 0, i = 0;
    cin >> n;
    int m = n;
    // divide number by 2 until it becames 1.
    int pre = 1;
    while((n != 1) && (n != -1)) {
        // for case 0
        if(pre == n) {
            i = 0;
            break;
        }
        // if the new divided number is not divisile by 2 , means not giving the remender as zero so break the loop at the instence.
        if(n % 2 != 0) {
            found = 1;
            break;
        }
        pre = n;
        n = n / 2;
        i++;
    }
    if(found)
        cout << "number is not the power" << endl;
    else
        cout << "number is  a valid power of 2^" << i << "= " << m << endl;
    return 0;
}