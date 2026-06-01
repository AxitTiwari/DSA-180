// https://leetcode.com/contest/weekly-contest-504/problems/digit-frequency-score/

#include <bits/stdc++.h>  
using namespace std;

class Solution {
public:
    int digitFrequencyScore(int n) {

        unordered_map<int, int> freq;
        while (n > 0) {

            int digit = n % 10;
            n = n / 10;

            freq[digit]++;
        }

        int sum = 0;
        for (auto &it : freq) {
            sum += it.first * it.second;
        }
        return sum;
    }
};