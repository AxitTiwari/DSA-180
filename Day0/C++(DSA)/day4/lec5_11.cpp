#include <iostream>
using namespace std;
int main() {
    //2
    for(int i = 0; i <= 15; i += 2) {
        cout << i << " ";

        if(i & 1) {
            continue;
        }
        i++;
        //i = 0 then 0000 & 001 then -> 0 no continue -> i -> 1 -> +2 = 3
        //i = 3 then 011 & 001 then ->001 > continue -> i += 2 = 5
        //i = 5 then 101 & 001 then -> 001 -> continue -> i += 2 = 7
        //i = 7 -> 9 -> 11 -> 13 -> 15
        //output = 0 3 5 7 9 11 13 15
    }
}