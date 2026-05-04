// https://leetcode.com/submissions/detail/1994895339/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void add_edge(int u, int v, unordered_map<int, list<int>>& graph) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> bfs(int node, int dest_level, unordered_map<int, list<int>>& graph) {

        queue<pair<int, int>> q; // (friend, level)
        q.push({node, 0});

        unordered_map<int, bool> visited;
        vector<int> people_at_kth_level;

        visited[node] = true;

        while (!q.empty()) {

            auto [person, level] = q.front();
            q.pop();

            if (level == dest_level) {

                // edge case : don't forget to add this person which is in dest level and not in queue now
                people_at_kth_level.push_back(person);
                while (!q.empty()) {
                    people_at_kth_level.push_back(q.front().first);
                    q.pop();
                }
                break;
            }

            for (auto nbr : graph[person]) {

                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({nbr, level+1});
                }
            }
        }
        return people_at_kth_level;
    }

public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        // first lets create the graph
        unordered_map<int, list<int>> graph;
        int cur_person = 0;

        for (int i = 0; i < friends.size(); i++) {
            for (auto f : friends[i]) {
                add_edge(i, f, graph);
            }
        }

        vector<int> people_at_level = bfs(id, level, graph);

        // count the video
        unordered_map<string, int> video_count;
        for (auto people : people_at_level) {

            vector<string> videos = watchedVideos[people];
            
            for (auto v : videos) {
                video_count[v]++;
            }
        }

        priority_queue <pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> min_heap;
        for (auto it : video_count) {
            min_heap.push({it.second, it.first});
        }

        vector<string> ans;
        while (!min_heap.empty()) {

            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};