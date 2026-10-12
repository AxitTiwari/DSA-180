#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxPrimes(int n, int s) {

        vector<int> res;
        for (int i = 2; i <= n; i++) {

            if (not_prime(i)) continue;

            if (s < i) break;
            
            s -= i;

            res.push_back(i);
        }
        return res;
    }
private:
    bool not_prime(int n) {

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return true;
        }
        return false;
    }
};