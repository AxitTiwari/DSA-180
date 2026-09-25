// https://leetcode.com/submissions/detail/2148802616/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n == 0) return false;

        return solve(n);
    }

private:
    bool solve(int n) {
        if (n == 1 || n == 0) return true;

        if (n % 2 != 0) return false;
        
        return isPowerOfTwo(n / 2);
    }
};