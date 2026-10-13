// https://leetcode.com/submissions/detail/2171029168/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        vector<int> prefix;
        prefix.push_back(0);

        int sum = 0;
        for (int cp : cardPoints) {
            sum += cp;
            prefix.push_back(sum);
        }

        int max_sum = 0;
        for (int i = 0; i <= k; i++) {

            int n = cardPoints.size();

            int sum = prefix[i] + prefix[n] - prefix[n-(k-i)];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};