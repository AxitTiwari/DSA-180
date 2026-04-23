// https://leetcode.com/problems/01-matrix/solutions/7777510/easy-to-understand-fast-clear-concise-by-gtas

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        // don't find shortest distance from 1 instead,
        // find distance of 1 from 0's

        // push cell having 0 to queue
        queue<pair<int, int>> q;
        for (int row = 0; row < mat.size(); row++) {

            for (int col = 0; col < mat[0].size(); col++) {

                if (mat[row][col] == 0) {
                    q.push({row, col});
                }
                else {
                    // to keep track of nodes waiting for getting shortest distance
                    mat[row][col] = -1;
                }
            }
        }

        // all neighbours
        vector<vector<int>> dir = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
        while (!q.empty()) {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (auto nbr : dir) {
                int new_x = x + nbr[0];
                int new_y = y + nbr[1];

                // valid cells and wating for shortest distance
                if (new_x >= 0 && new_x < mat.size() && 
                    new_y >= 0 && new_y < mat[0].size() && 
                    mat[new_x][new_y] == -1
                ) {
                    mat[new_x][new_y] = 1 + mat[x][y];
                    q.push({new_x, new_y});
                }
            }
        }
        return mat;
    }
};