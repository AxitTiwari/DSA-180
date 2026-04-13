// Total 4 errors - (not 4 they were 1000000000000 work bro)
/*
1. wronge dist size
2. wronge push by prority in min-heap
3. have to skip but used break
4. wronge return dist[node] but we have to return w
*/

// https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/1977146792

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

class Solution {
private:
    unordered_map<int, list<pair<int, int>>> adj;

    void add_edge(int s, int d, int w) {

        adj[s].push_back({d, w});
        adj[d];
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        for (auto node : flights) {

            int s = node[0];
            int d = node[1];
            int w = node[2];
            
            add_edge(s, d, w);
        }

        vector<vector<int>> dist(n, vector<int>(k+2, 1e9));
        dist[src][0] = 0;

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0, src, 0});

        int ans = 1e9;

        while (!pq.empty()) {

            auto [w, node, count_stops] = pq.top();
            pq.pop();

            if (count_stops > k+1) continue;

            if (node == dst) {
                ans = min(ans, w);
                continue;
            }

            if (w > ans) continue;

            if (count_stops == k + 1) continue;

            for (auto nbr : adj[node]) {

                int n = nbr.first;
                int w_n = nbr.second;

                if (dist[n][count_stops+1] > w + w_n) {

                    int k_n = count_stops + 1;

                    dist[n][count_stops+1] = w + w_n;

                    pq.push({w + w_n, n, k_n});
                }

            }
        }

        if (ans != 1e9) return ans;

        return -1;
    }
};