// https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/2033688312

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, list<pair<int, int>>> graph;
    void add_edge(int u, int v, int d) {
        graph[u].push_back({v, d});
    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        for (auto flight : flights) {

            add_edge(flight[0], flight[1], flight[2]);
        }

        queue<tuple<int, int, int>> q;

        q.push({0, src, 0}); // {stops, node, dist}

        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        while (!q.empty()) {

            auto [stop, node, dist] = q.front();
            q.pop();

            if (stop > k) continue;

            for (auto &[nbr, d] : graph[node]) {

                if (distance[nbr] > d + dist && stop <= k) {
                    q.push({stop+1, nbr, d+dist});
                    distance[nbr] = d + dist;
                }
            }
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst]; 
    }
};