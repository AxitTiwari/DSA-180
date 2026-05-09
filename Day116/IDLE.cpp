// https://leetcode.com/problems/the-time-when-the-network-becomes-idle/submissions/1999138308
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void add_edge(int u, int v, unordered_map<int, list<int>>& graph) {
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    vector<int> bfs(unordered_map<int, list<int>>& graph, int n) {

        queue<int> q;
        q.push(0);

        vector<int> time(n, -1);
        time[0] = 0;
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto nbr : graph[node]) {

                if (time[nbr] == -1) {
                    time[nbr] = time[node] + 1; // -1 + 1 = 0
                    q.push(nbr);
                }
            }
        }
        return time;
    }

    int earliest_second(vector<int>& time, int n, vector<int>& patience) {

        int t = 0;
        for (int node = 1; node < n; node++) {

            int total_time = time[node] * 2;
            int rate = patience[node];
            int extra_meassage = (total_time - 1) / rate;

            int last_time_sends_meassage = extra_meassage * rate;
            int total_time_node = last_time_sends_meassage + total_time;

            t = max(t, total_time_node);
        }
        return t + 1;
    }

public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        
        int n = patience.size();

        unordered_map<int, list<int>> graph;
        for (auto e : edges) {
            add_edge(e[0], e[1], graph);
        }

        vector<int> time = bfs(graph, n);
        return earliest_second(time, n, patience);
    }
};