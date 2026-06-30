// https://leetcode.com/problems/reverse-bits/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int bit = (n >> i) & 1;
            res = res | (bit << (31 - i));
        }
        return res;
    }
};