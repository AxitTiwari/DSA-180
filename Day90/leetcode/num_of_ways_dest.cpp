// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/submissions/1977430112

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<int, int>> adj[n];

        for (auto it : roads) {

            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        std::priority_queue <pair<long long, long long>, std::vector<pair<long long, long long>>, std::greater<pair<long long, long long>>> pq;

        vector<long long> dist(n, 1e12), ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        int mod = (int)(1e9 + 7);

        while (!pq.empty()) {

            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {

                long long adj_node = it.first;
                long adj_w = it.second;

                // first time visit
                if (dis + adj_w < dist[adj_node]) {

                    dist[adj_node] = dis + adj_w;
                    pq.push({dis + adj_w, adj_node});
                    ways[adj_node] = ways[node];
                }
                else if (dis + adj_w == dist[adj_node]) {
                    ways[adj_node] = (ways[adj_node] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};