#include <iostream>
#include <math.h>
int main() {
/*
    decimal to binary
    by logic 1st wala.
    number / 2
    error aa rahi hai , dekh lena bad me 
*/
    int n;
    std::cin >> n;
    int ans = 0;
    int i = 0;
    while(n != 0) {
        int rem = n % 2;
        ans = (rem * pow(10 , i)) + ans;
        std::cout << ans << std::endl;
        n = n / 2;
        i++;
    }
    std::cout << "answer is : " << ans << std::endl;
    return 0;
}