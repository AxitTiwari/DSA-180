// https://leetcode.com/problems/last-stone-weight/submissions/1981920588

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> max_heap;

        for (int stone : stones) {
            max_heap.push(stone);
        }

        while (max_heap.size() > 1) {

            int stone1 = max_heap.top();
            max_heap.pop();

            int stone2 = max_heap.top();
            max_heap.pop();

            int result = stone1 > stone2 ? (stone1-stone2) : (stone2-stone1);

            max_heap.push(result);
        }

        return max_heap.top();
    }
};