// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/submissions/2034162048

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        for (auto edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (int k = 0; k < n; k++) {

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int resultant_city = -1;
        int ans = n;
        for (int city = 0; city < n; city++) {

            int cnt = 0;
            for (int nbr = 0; nbr < n; nbr++) {

                if (dist[city][nbr] <= distanceThreshold) cnt++;
            }

            if (cnt <= ans) {
                ans = cnt;
                resultant_city = city;
            }
        }
        return resultant_city;
    }
};