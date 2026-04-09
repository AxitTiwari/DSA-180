#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    bool solve(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n, -1);   // -1 = uncolored
        
        for(int i = 0; i < n; i++) {
            
            if(color[i] != -1) continue;  // already visited
            
            queue<int> q;
            q.push(i);
            color[i] = 0;   // start coloring
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                
                for(auto neigh : graph[node]) {
                    
                    if(color[neigh] == -1) {
                        // assign opposite color
                        color[neigh] = 1 - color[node];
                        q.push(neigh);
                    }
                    else if(color[neigh] == color[node]) {
                        // same color conflict
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        return solve(graph);
    }
};