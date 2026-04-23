#include <iostream>
using namespace std;

// ye khud se kiya same question hai 'book allocation' , debug bhi khud se hi kiya😉

int isPossible(int books[], int no_of_pages, int no_of_students, int possible_solution) {

    // ye mene banaya hai
    bool posibility_of_answer = false;
    int sum_pages = 0;
    int page_num = 0;
    for(int i = 0; i < no_of_students; i++) {

        sum_pages = 0;

        for(int j = page_num; j < no_of_pages; j++, page_num++) {

            sum_pages += books[j];
            if(sum_pages > possible_solution) {
                sum_pages -= books[j];
                break;
            }

            // cout << "page num: " << page_num;
            // cout << endl;
        }

        // cout << "sum of pages " << sum_pages << endl;
        // cout << "page number for student " << i + 1 << "is " << page_num << endl;
    }
    // not a possible sotion
    if(page_num != no_of_pages) {
        return posibility_of_answer;
    }
    else {
        posibility_of_answer = true;
        return posibility_of_answer;
    }

}


bool possible(int books[], int no_of_pages, int no_of_students, int possible_solution) {

    // from lecture(15)
    int student_count = 0;
    int page_sum = 0;

    for(int i = 0; i < no_of_pages; i++) {

        if(page_sum + books[i] <= possible_solution) {
            page_sum += books[i];
        }
        else {
            student_count++;

            if(student_count > no_of_students || books[i] > possible_solution) {
                return false;
            }
            page_sum = books[i];
        }
    }

    return true;
}

int main() {

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

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += books[i];
    }

    // cout << "sum = " << sum << endl;

    int start = 0;
    int end = sum;
    int mid = start + (end - start) / 2;
    int result;
    int answer = INT16_MAX;

    while(start <= end) {

        // result = isPossible(books, n, m, mid);
        // cout << "result: " << result << endl;

        if(isPossible(books, n, m, mid)) {
            if(answer > mid) {
                answer = mid;
            }
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;

        // cout << "start: " << start << endl;
        // cout << "mid: " << mid << endl;
        // cout << "end: " << end << endl;
    }

    if(answer != INT16_MAX) {
        cout << "possible solution is: " << answer << endl;
    }
    else {
        cout << "No possible solution" << endl;
    }

    return 0;
}