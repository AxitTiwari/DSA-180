#include <iostream>
int main() {
/*
    switch & Functions

    switch(expression) {
        case constant: <-- constant can not be float and string
            break;
        default: <-- default is optional
        }
*/
    int num = 1;
    char ch = '1';

    switch(ch) {
        case 1: 
            std::cout << "First" << std::endl;
            break;

        case '1': 
            switch(num) {
                case 1: 
                    std::cout << "inside switch case wala 1" << std::endl;
                    break;
            }
            break;

        default: 
            std::cout << "Default" << std::endl;

    }
    return 0;
}