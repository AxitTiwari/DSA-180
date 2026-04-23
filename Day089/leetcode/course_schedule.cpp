// https://leetcode.com/problems/course-schedule/submissions/1976093116

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, list<int>> adj_list;

    bool dfs(int node, unordered_map<int, int>& color) {

        color[node] = 1; // visiting

        for (auto nbr : adj_list[node]) {

            if (color[nbr] == 0) {

                if (dfs(nbr, color)) return true;
            }
            else if (color[nbr] == 1) {
                return true;
            }
        }

        color[node] = 2; // finished
        return false;
    }

    bool is_cycle(int num_courses) {

        unordered_map<int, int> color;

        for (int i = 0; i < num_courses; i++) {
            color[i] = 0; // not visited
        }

        for (int i = 0; i < num_courses; i++) {
            
            if (color[i] == 0) {
                if (dfs(i, color)) return true;
            }
        }
        return false;
    }

    void create_graph(vector<vector<int>>& prerequisites) {

        for (int row = 0; row < prerequisites.size(); row++) {

            int u = prerequisites[row][0];
            int v = prerequisites[row][1];

            adj_list[u].push_back(v);
            adj_list[v];
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
        create_graph(prerequisites);

        if (is_cycle(numCourses)) {
            return false;
        }
        return true;
    }
};