#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int sum_prime(int n) {

        vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i*i <= n; i++) {

            if (is_prime[i]) {

                // imp
                for (int j = i*i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < is_prime.size(); i++) {
            if (is_prime[i]) {
                sum += i;
            }
        }
        return sum;
    }
    int sumOfPrimesInRange(int n) {

        int reverse_digit = 0;
        int temp = n;

        while (temp) {

            int digit = temp % 10;
            temp = temp / 10;

            // imp
            reverse_digit = reverse_digit * 10 + digit;
        }

        cout << reverse_digit << endl;
        
        int l = min(n, reverse_digit);
        int r = max(n, reverse_digit);

        // imp
        return sum_prime(r) - sum_prime(l-1);
    }
};