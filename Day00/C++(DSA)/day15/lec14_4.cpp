#include <iostream>
using namespace std;

int mySqrt(int x) {

    int start = 0;
    int end = x;
    int mid = start + (end - start) / 2;
    int ans = -1;
    
    while(start <= end) {
        if(mid * mid == x) {
            return mid;
        }
        else if(mid * mid < x) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

double sqrt_precision(int original_num, int precision, int ans) {

    double factor = 1;
    double result = ans;

    for(int i = 0; i < precision; i++) {
        factor = factor / 10;
        for(double j = result; j * j <= original_num; j = j + factor) {
            result = j;
        }
    }

    return result;
}


int main() {

    /*
    Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
    You must not use any built-in exponent function or operator.
    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 
    */

    int x;
    cin >> x;

    int square_root = mySqrt(x);
    cout << "square root " << square_root << endl;

    double num = sqrt_precision(x, 3, square_root);

    cout << "precised square root " << num << endl;

    return 0;
}