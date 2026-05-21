#include <iostream>
#include <queue>

using namespace std;

int main() {

    /*
        queue - FIFO
    */

    queue<string> q;

    q.push("I");
    q.push("Love");
    q.push("Myself");

    cout << "size before pop " << q.size() << endl;

    cout << "First element " << q.front() << endl;
    q.pop();
    cout << "First element " << q.front() << endl;

    cout << "size after pop " << q.size() << endl;

}