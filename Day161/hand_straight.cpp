// https://leetcode.com/problems/hand-of-straights/submissions/2042463801

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if (hand.size() % groupSize) return false;

        unordered_map<int, int> count;
        for (int n : hand) count[n] += 1;

        priority_queue<int, vector<int>, greater<int>> min_h;

        for (auto &pair : count) {
            min_h.push(pair.first);
        }

        while (!min_h.empty()) {

            int first = min_h.top();

            for (int i = first; i < first + groupSize; i++) {

                if (count.find(i) == count.end()) return false;

                count[i]--;

                if (count[i] == 0) {
                    if (i != min_h.top()) return false;
                    min_h.pop();
                }
            }
        }
        return true;
    }
};
