#include <iostream>
using namespace std;
int main() {
/*
    same question but with the help of switch case (dek ke gpt se)
*/
    int amount;
    cin >> amount;

    int denom = 100; //<- variable
    int hNote, fNote, tNote, oNote;

    switch(denom) {
        case 100:
            hNote = amount / 100;
            amount = amount - hNote * 100;
            denom = 50;
            // no break , so that it can execute further 

        case 50:
            fNote = amount / 50;
            amount = amount - fNote * 50;
            denom = 20;
        
        case 20:
            tNote = amount / 20;
            amount = amount - tNote * 20;
            denom = 1; // so that it can points to the next condition

        case 1:
            oNote = amount;
            amount = amount - oNote;
            break;
        
        default:
            cout << "error" << endl;
    }

    cout << "100 = " << hNote << endl;
    cout << "50 = " << fNote << endl;
    cout << "20 = " << tNote << endl;
    cout << "1 = " << oNote << endl;
}