// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/submissions/1997487527

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshall(int n, vector<vector<int>>& edges) {

    vector<vector<int>> dist(n, vector<int>(n, 1e7));

    // Distance from node to itself = 0
    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // adjancency matrix
    for(auto edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        dist[u][v] = wt;
        dist[v][u] = wt; 
    }

    // Floyd Warshall
    for(int k = 0; k < n; k++) {

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(dist[i][k] != 1e7 && dist[k][j] != 1e7) {

                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dist = floydWarshall(n, edges);

        pair<int, int> ans_city = {-1, INT_MAX};
        for (int i = 0; i < dist.size(); i++) {

            // calculate cities having distance atmost distanceThreshold for every city
            int cities = 0;
            for (int j = 0; j < dist[0].size(); j++) {

                if (dist[i][j] <= distanceThreshold) {
                    cities++;
                }
            }

            if (ans_city.second >= cities) {
                ans_city = {i, cities};
            } 
        }
        return ans_city.first;
    }
};