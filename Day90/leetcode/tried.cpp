// PATH WITH MINIMUM EFFORT (leetcode 1631)


// #include <algorithm>
// struct hash_pair {
//     size_t operator()(const pair<int, int>& p) const {
//         return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
//     }
// };

// class Solution {
// private:
//     int bfs(int r, int c, unordered_map<pair<int, int>, pair<int, bool>, hash_pair>& visited, vector<vector<int>>& heights) {

//         queue<pair<pair<int, int>, int>> q; // ((x, y), dist)
//         q.push({{r, c}, heights[r][c]});

//         int ans = INT_MAX;

//         vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//         while (!q.empty()) {

//             // pop node from queue and extract the data
//             int x = q.front().first.first;
//             int y = q.front().first.second;
//             int h = q.front().second;

//             if (x == heights.size()-1 && y == heights[0].size()-1) {
//                 ans = min(ans, h);
//             }

//             // check all its neighbours
//             for (auto d : dir) {

//                 int new_x = x + d[0];
//                 int new_y = y + d[1];
                
//                 // check validity
//                 if (
//                     new_x >= 0 && new_x < heights.size() &&
//                     new_y >= 0 && new_y < heights[0].size() 
//                 ) {

//                     // if not visited -> compute heights
//                     if (!visited[{new_x, new_y}].second) {

//                         int new_h = heights[new_x][new_y];
//                         int diff = max(h, abs(h - new_h));

//                         q.push({{new_x, new_y}, diff});
//                         visited[{new_x, new_y}] = {diff, true};
//                     }
//                     else {

//                         // if it is already visited -> check for optimum path (may be new one is better one)
//                         int existing_diff = visited[{new_x, new_y}].first;

//                         int new_h = heights[new_x][new_y];
//                         int diff = abs(h - new_h);

//                         // push into the queue
//                         if (diff < existing_diff) {
//                             q.push({{new_x, new_y}, diff});
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
        
//         unordered_map<pair<int, int>, pair<int, bool>, hash_pair> visited; // (key : (dist, is_visited))
//         int min_effort = INT_MAX;
//         for (int r = 0; r < heights.size(); r++) {
//             for (int c = 0; c < heights[0].size(); c++) {
                
//                 if (!visited[{r, c}].second) {
//                     min_effort = min(min_effort, bfs(r, c, visited, heights));
//                 }
//             }
//         }
//         return min_effort;
//     }
// };