#include <iostream>
using namespace std;
int main() {
/*
pattern 21
        1234554321
        1234**4321
        123****321
        12******21
        1********1

        12344321
        123**321
        12****21
        1******1
*/
    int i, j, n;
    cin >> n;
    i = 0;
    while(i < n) {
        j = 0;
        //1st triangle
        while(j < n - i) {
            cout << j + 1;
            j++;
        }
        //2nd triangle
        int turn = i * 2;
        while(turn) {
            cout << "*";
            turn--;
        }
        //3rd triangle
        j = n - i;
        while(j > 0) {
            cout << j;
            j--;
        }
        cout << endl;
        i++;
    }
}