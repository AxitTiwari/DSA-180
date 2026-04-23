#include <iostream>
#include <deque>
using namespace std;

int solve(int* arr, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    // ----addition of first k size window-------
    for (int i = 0; i < k; i++) {

        while (!maxi.empty() && arr[maxi.front()] <= arr[i]) {
            maxi.pop_back();
        }

        while (!mini.empty() && arr[mini.front()] >= arr[i]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    for (int i = k; i < n; i++) {

        ans += arr[maxi.front()] + arr[mini.front()];

        // ---next window----

        // removal
        while (i - maxi.front() >= k) {
            maxi.pop_front();
        }

        while (i - mini.front() >= k) {
            mini.pop_front();
        }

        // -----addition------
        while (!maxi.empty() && arr[maxi.front()] <= arr[i]) {
            maxi.pop_back();
        }

        while (!mini.empty() && arr[mini.front()] >= arr[i]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    // -----next window-----
    ans += arr[maxi.front()] + arr[mini.front()];
    return ans;

}

int main() {

    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int size  = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int ans = solve(arr, size, k);

    cout << "sum of min and max: " << ans << endl;

    return 0;
    
}