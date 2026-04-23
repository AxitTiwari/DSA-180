#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool monobit(int n) {

        if (n == 0 || n == 1)
            return true;

        // rightmost bit
        int prevBit = n & 1;
        while (n > 1) {
            n = n >> 1;
            int newBit = n & 1;
            if (prevBit != newBit)
                return false;
            prevBit = newBit;
        }
        cout << "n: " << n << endl;
        return true;
    }

public:
    int countMonobit(int n) {

        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (monobit(i)) {
                cout << i << " ";
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {

    Solution sol;
    int n;
    cin >> n;

    cout << sol.countMonobit(n) << endl;

    return 0;
}