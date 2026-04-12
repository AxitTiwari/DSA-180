// https://leetcode.com/problems/number-of-provinces/submissions/1976570472

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int src, int dest, vector<vector<int>>& isConnected, vector<bool>& visited) {

        visited[src] = true;

        for (int i = 0; i < isConnected.size(); i++) {

            if (!visited[i] && isConnected[src][i]) {
                dfs(i, dest, isConnected, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        

        int province = 0;

        vector<bool> visited(isConnected.size(), false);
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {

                if (!visited[i] && isConnected[i][j] == 1) {
                    dfs(i, j, isConnected, visited);
                    province++;
                }
            }
        }

        return province;
    }
};