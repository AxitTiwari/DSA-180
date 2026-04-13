// https://leetcode.com/problems/network-delay-time/submissions/1977178048

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <climits>
using namespace std;

class Solution {
private:
    unordered_map<int, list<pair<int, int>>> adj;

    void add_edge(int s, int d, int w) {
        adj[s].push_back({d, w});
        adj[d];
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // create the graph
        for (auto node : times) {

            int u = node[0];
            int v = node[1];
            int w = node[2];

            add_edge(u, v, w);
        }

        unordered_map<int, int> time;

        for (int i = 1; i <= n; i++) {
            time[i] = 1e9;
        }

        time[k] = 0;

        std::priority_queue <pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int edge = it.first;
            int node = it.second;

            for (auto nbr : adj[node]) {

                if (time[nbr.first] > edge + nbr.second) {

                    time[nbr.first] = edge + nbr.second;
                    pq.push({time[nbr.first], nbr.first}); 
                }
            }
        }

        int ans = INT_MIN;
        for (auto it : time) {
            if (it.second == 1e9) return -1;

            ans = max(ans, it.second);
        }
        return ans;
    }
};