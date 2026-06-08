// https://leetcode.com/problems/last-stone-weight/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() >= 2) {

            int n1 = pq.top();
            pq.pop();

            int n2 = pq.top();
            pq.pop();

            int smash = abs(n1 - n2);

            if (smash != 0) pq.push(smash);
        }
        return pq.empty() ? 0 : pq.top();
    }
};