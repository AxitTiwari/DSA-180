#include <iostream>
using namespace std;
int main() {
/*
    H.W problem
    amount = 1330
    how many 100, 50, 20 and 1 rupees note will be reqrired for fullfilment of the amount.
*/
    int amount, hNote, fNote, tNote, oNote;
    cin >> amount;
    int amo = 100;  // amo = 100 -> 50 -> 20 -> 1
    hNote = amount / 100;
    amount = amount - hNote * 100;
    fNote = amount / 50;
    amount = amount - fNote * 50;
    tNote = amount / 20;
    amount = amount - tNote * 20;
    oNote = amount;

    cout << "100 = " << hNote << endl;
    cout << "50 = " << fNote << endl;
    cout << "20 = " << tNote << endl;
    cout << "1 = " << oNote << endl;
    return 0;
}