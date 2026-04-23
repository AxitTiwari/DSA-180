#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& m) {

        if (x >= 0 && x < n &&
            y >= 0 && y < n &&
            visited[x][y] == 0 &&
            m[x][y] == 1) {
            return true;
        }
        return false;
    }

    void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string& path) {

        // base case
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // Down
        if (isSafe(x + 1, y, n, visited, m)) {
            path.push_back('D');
            solve(m, n, ans, x + 1, y, visited, path);
            path.pop_back();
        }

        // Left
        if (isSafe(x, y - 1, n, visited, m)) {
            path.push_back('L');
            solve(m, n, ans, x, y - 1, visited, path);
            path.pop_back();
        }

        // Right
        if (isSafe(x, y + 1, n, visited, m)) {
            path.push_back('R');
            solve(m, n, ans, x, y + 1, visited, path);
            path.pop_back();
        }

        // Up
        if (isSafe(x - 1, y, n, visited, m)) {
            path.push_back('U');
            solve(m, n, ans, x - 1, y, visited, path);
            path.pop_back();
        }

        visited[x][y] = 0; // backtrack
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {

        int n = maze.size();
        vector<string> ans;

        if (maze[0][0] == 0)
            return ans;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";

        solve(maze, n, ans, 0, 0, visited, path);
        sort(ans.begin(), ans.end());

        return ans;
    }
};
