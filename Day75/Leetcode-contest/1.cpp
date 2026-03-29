#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMatchingIndex(string s) {

        int n = s.length();
        for (int i = 0, j = n-i-1; i < n && j >= 0; i++, j--) {

            if (s[i] == s[j]) return i;
        }
        return -1;
    }
};