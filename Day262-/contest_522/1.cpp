#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRotations(string s) {

        int min_rotation = 0;
        
        int ptr = 0;
        for (char ch : s) {

            int digit = ch - '0';

            int r = abs(digit - ptr);
            int rotation = min(r, 10-r) ;

            min_rotation += rotation;
            ptr = digit;
        }
        return min_rotation;
    }
};