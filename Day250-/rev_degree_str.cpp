//https://leetcode.com/submissions/detail/2147898698/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        
        int r_degree = 0;
        for (int i = 0; i < s.length(); i++) r_degree += (i+1) * ('z' - s[i] + 1);
        return r_degree;
    }
};