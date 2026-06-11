// https://leetcode.com/problems/number-of-islands/submissions/2029343840

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> rank, parent;
public:
    DisjointSet(int n) {

        rank.resize(n+1, 0);
        parent.resize(n+1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find_parent(int node) {

        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find_parent(parent[node]);
    }

    bool union_by_rank(int u, int v) {

        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        // same component
        if (parent_u == parent_v) return false;

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
        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size(), m = grid[0].size();
        
        int islands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') islands++;
            }
        }

        vector<pair<int, int>> nbr = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        DisjointSet dsu(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (grid[i][j] == '0') continue;

                int key = i * m + j;

                for (auto &[r, c] : nbr) {

                    int new_x = i + r;
                    int new_y = j + c;

                    if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || grid[new_x][new_y] == '0') continue;

                    int new_key = new_x * m + new_y;

                    if (dsu.union_by_rank(key, new_key)) {
                        islands--;
                    }
                }
            }
        }
        return islands;
    }
};

// 2.
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
        
//         int count = 0;
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[0].size(); j++) {
                
//                 int key = i * grid[0].size() + j;

//                 if (grid[i][j] == '1' && !visited[key]) {
//                     dfs(i, j, grid);
//                     count += 1;
//                 }
//             }
//         }
//         return count;
//     }

// private:
//     unordered_map<int, bool> visited;
//     void dfs(int x, int y, vector<vector<char>>& grid) {

//         int key = x * grid[0].size() + y;
//         visited[key] = true;

//         vector<pair<int, int>> nbr = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

//         for (auto &[r, c] : nbr) {

//             int new_x = x + r;
//             int new_y = y + c;

//             if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size()) continue;

//             int new_key = new_x * grid[0].size() + new_y;
//             if (!visited[new_key] && grid[new_x][new_y] == '1') {
//                 dfs(new_x, new_y, grid);
//             }
//         }
//     }
// };
