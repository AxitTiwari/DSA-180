// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/submissions/2074790443

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int res = -1;
        int min_of_max = INT_MAX;
        int n = edges.size();

        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);

        dfs(node1, 0, edges, dist1);
        dfs(node2, 0, edges, dist2);

        for (int i = 0; i < n; i++) {
            if (dist1[i] >= 0 and dist2[i] >= 0) {

                int max_dist = max(dist1[i], dist2[i]);
                if (max_dist < min_of_max) {
                    min_of_max = max_dist;
                    res = i;
                }
            }
        }
        return res;
    }
private:
    void dfs(int node, int dis, vector<int>& edges, vector<int>& dist) {

        if (node == -1 || dist[node] != -1) return;

        dist[node] = dis;

        dfs(edges[node], dis+1, edges, dist);
    }
};