// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/submissions/2062603618

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int s = max(weights), e = sum(weights);

        int res = 0;
        while (s <= e) {

            int m = s + (e - s) / 2;

            int day = find_days(weights, m);

            if (day <= days) {
                res = m;
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }
        return res;
    }
private:

    int sum(vector<int> &weights) {
        int sum = 0;
        for (int &weight : weights) {
            sum += weight;
        }
        return sum;
    }

    int max(vector<int> &weights) {
        int m = INT_MIN;
        for (int &weight : weights) {
            m = weight > m ? weight : m;
        }
        return m;
    }

    int find_days(vector<int> &weights, int cap) {

        int days = 1, load = 0;
        for (int &weight : weights) {

            if (load + weight > cap) {
                days += 1;
                load = weight;
            }
            else {
                load += weight;
            }
        }
        return days;
    }
};