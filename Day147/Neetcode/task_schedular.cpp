// https://leetcode.com/problems/task-scheduler/submissions/2026983432

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task-'A']++;
        }

        priority_queue<int> max_heap;
        for (int i = 0; i < 26; i++) {

            if (freq[i] == 0) continue;

            max_heap.push(freq[i]);
        }

        queue<pair<int, int>> q;
        int time = 0;
        while (!max_heap.empty() || !q.empty()) {

            time += 1;

            if (!max_heap.empty()) {
                int cnt = max_heap.top() - 1;
                max_heap.pop();

                if (cnt) {
                    q.push({cnt, time+n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                max_heap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};