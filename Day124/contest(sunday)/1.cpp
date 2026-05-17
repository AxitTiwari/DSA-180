#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int abs(int a, int b) {
        return a > b ? a - b : b - a;
    }
    bool isAdjacentDiffAtMostTwo(string s) {

        for (int i = 0; i < s.length()-1; i++) {

            if (abs(s[i] + '0', s[i+1] + '0') > 2) return false;
        }
        return true;
    }
};