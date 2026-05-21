#include <iostream>
using namespace std;

int fibonacci(int n){
    int a = 0, b = 1, nextTerm;

    if(n == 1){
        return 0;
    }
    else{
        if(n == 2) {
            return 1;
        }
    }

    for(int i = 2; i < n; i++) {
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }

    return b;
}
int main() {
/*
    Nth term of fibonacci series 
*/
    int n;
    cin >> n;

    int ans = fibonacci(n);
    cout << "Nth term is " << ans << endl;
    return 0;
}