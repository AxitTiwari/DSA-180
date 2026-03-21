#include <iostream>
using namespace std;

// galat hai ye . Video dhang se dekh


int allocate_books(int books[], int no_of_books, int no_of_students) {

    int start = 0;
    int end = 100;
    int mid = start + (end - start) / 2;

    int sum_pages;
    int idx = 0;
    int result = -1;
    int previos_result = INT32_MAX;

    while(start <= end) {

        for(int i = 0; i < no_of_students; i++) {

            sum_pages = 0;

            for(int j = idx; j < no_of_books; j++, idx++) {

                if(sum_pages < mid)
                    sum_pages += books[j];
                else
                    break;

                if(sum_pages > result) {
                    result = sum_pages;
                    cout << "result: " << result << endl;
                }

                cout << "idx: " << idx << endl;
            }

            cout << "student no" << no_of_students << endl;

            if(previos_result > result)
                previos_result = result;
        }

        if(previos_result > mid)
                end = mid - 1;
            
        if(previos_result < mid)
                start = mid + 1;

        mid = start + (end - start) / 2;
    }

    return previos_result;
}


int main() {
    /*
        Book allocation problem
    */

    int n;
    cout << "Enter total books: ";
    cin >> n;

    int m;
    cout << "Enter the number of students: ";
    cin >> m;

    int books[20];
    cout << "Enter pages of each books: ";
    for(int i = 0; i < n; i++) {
        cin >> books[i];
    }

    int result = allocate_books(books, n, m);

    cout << result << endl;

    return 0;
}