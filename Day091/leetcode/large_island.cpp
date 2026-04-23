// https://leetcode.com/problems/making-a-large-island/submissions/1978051792

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {

        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int node) {

        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find_parent(parent[node]);
    }

    void union_by_rank(int u, int v) {

        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        // same component
        if (parent_u == parent_v) return;

        if (rank[parent_u] < rank[parent_v]) {
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        }
        else {
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }

    void union_by_size(int u, int v) {

        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        // same component
        if (parent_u == parent_v) return;

        if (size[parent_u] < size[parent_v]) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};

class Solution {
private:
    bool is_valid(int x, int y, int n) {

        return x >= 0 && x < n && y >= 0 && y < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n =  grid.size();
        DisjointSet ds(n*n);

        // step 1: group all the components using disjoint set
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 0) continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};

                // go all possible directions
                for (int nbr = 0; nbr < 4; nbr++) {

                    int newr = row + dr[nbr];
                    int newc = col + dc[nbr];

                    if (is_valid(newr, newc, n) && grid[newr][newc] == 1) {

                        // keys for disjoint set
                        int node_no = row * n + col;
                        int nbr_node_no = newr * n + newc;

                        // group them
                        ds.union_by_size(node_no, nbr_node_no);
                    }
                }
            }
        }

        // Step2 : check for all 0's
        int mx = INT_MIN;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1) continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};

                set<int> component;
                for (int nbr = 0; nbr < 4; nbr++) {

                    int newr = row + dr[nbr];
                    int newc = col + dc[nbr];

                    if (is_valid(newr, newc, n) && grid[newr][newc] == 1) {
                        component.insert(ds.find_parent(newr * n + newc));
                    }
                }

                int size_total = 0;
                for (auto it : component) {
                    size_total += ds.size[it];
                }
                mx = max(mx, size_total+1);
            }
        }

        // if no 0 is present
        for (int cell_no = 0; cell_no < n*n; cell_no++) {

            mx = max(mx, ds.size[ds.find_parent(cell_no)]);
        }
        return mx;
    }
};