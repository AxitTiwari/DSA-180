// https://leetcode.com/problems/keys-and-rooms/submissions/1994371455

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, bool> visited;

    void dfs(int cur_room, vector<vector<int>>& rooms) {

        visited[cur_room] = true;

        for (auto to_room : rooms[cur_room]) {
            if (!visited[to_room]) {
                dfs(to_room, rooms);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        // simple
        
        dfs(0, rooms);

        return (visited.size() == rooms.size());
    }
};