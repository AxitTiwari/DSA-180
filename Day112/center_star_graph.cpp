// https://leetcode.com/problems/find-center-of-star-graph/submissions/1996065997

#include <vector>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        pair<int, int> center_node = {edges[0][0], edges[0][1]};
        for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            if (i == 1) {
                center_node.first = u == center_node.first ? u : (u == center_node.second ? u : v);
            }
            else {
                center_node.first = u == center_node.first ? u : v;
            }   
        }
        return center_node.first;
    }
};