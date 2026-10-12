// https://leetcode.com/submissions/detail/2168739531/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeFibonacciSum(int n) {

        int sum = 2;
        int t1 = 0, t2 = 1, t3 = 1;
        while (sum <= n) {

            if (sum == n) return true;

            int next = t2 + t3;
            sum += next;
            sum -= t1;
            t1 = t2;
            t2 = t3;
            t3 = next;
        }
        return false;
    }
};