// https://leetcode.com/problems/network-delay-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, list<pair<int, int>>> graph;

        for (auto node : times) {
            graph[node[0]].push_back({node[1], node[2]});
        }

        vector<int> time(n+1, 1e9);

        time[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {

            auto [t, node] = pq.top();
            pq.pop();

            for (auto &[nbr, nbr_time] : graph[node]) {

                if (time[nbr] > t + nbr_time) {

                    time[nbr] = t + nbr_time;
                    pq.push({time[nbr], nbr});
                }
            }
        }
        
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {

            if (time[i] == 1e9) return -1;

            ans = max(ans, time[i]);
        }
        return ans;
    }
};