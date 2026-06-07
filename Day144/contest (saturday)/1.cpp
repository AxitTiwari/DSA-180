#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool consecutiveSetBits(int n) {

        string binary;
        while (n) {
            int bit = n & 1;
            binary += to_string(bit);
            n = n >> 1;
        }

        int l = 0, r = 0;
        int pair = 0;
        while (r < binary.length()) {

            if (binary[r] == '1') {
                r++;
            }
            else {
                r++;
                l = r;
            }

            if (r - l >= 2) {
                l++;
                pair++;
            }
        }
        return pair == 1;
    }
};