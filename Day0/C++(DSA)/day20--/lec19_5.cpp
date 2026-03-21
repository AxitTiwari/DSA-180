#include <iostream>
#include <stack>

using namespace std;

int main() {

    /*
        stack() - LIFO (last-in first-out)
    */

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top element " << s.top() << endl;

    s.pop();

    cout << "Top element " << s.top() << endl;

    cout << "Size of stack " << s.size() << endl;

    cout << "Empty or not " << s.empty() << endl;

    stack<string> my_s;

    my_s.push("axit");
    my_s.push("jasspreet");
    my_s.push("tiwari");

    cout << "Top element " << my_s.top() << endl;

    my_s.pop();

    cout << "Top element " << my_s.top() << endl;

    return 0;
}