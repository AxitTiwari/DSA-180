#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {

        vector<int> pre;

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {

            long long sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];

                if (is_valid(sum, x)) cnt++;
            }
        }

        return cnt;
    }
private:
    bool is_valid(long long n, int x) {

        if (n % 10 != x) return false;

        while (n >= 10) {
            n = n / 10;
        }

        return n == x;
    }
};