// https://leetcode.com/problems/koko-eating-bananas/submissions/2021960313

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int get_max(vector<int> &piles) {

        int m = piles[0];
        for (int pile : piles) {
            m = max(m, pile);
        }
        return m;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int max = get_max(piles);

        int min_speed;

        // search space;
        int s = 1, e = max;
        while (s <= e) {

            int k = s + (e - s) / 2;

            int total_time = 0;
            for (int pile : piles) {
                total_time += (pile + k - 1) / k;
            }

            if (total_time <= h) {
                min_speed = k;
                e = k - 1;
            }
            else {
                s = k + 1;
            }
        }
        return min_speed;
    }
};
