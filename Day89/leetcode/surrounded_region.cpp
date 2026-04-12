// https://leetcode.com/problems/surrounded-regions/submissions/1976198285

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& is_safe) {

        is_safe[x][y] = true;

        vector<vector<int>> dir = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
        for (auto d : dir) {

            int new_x = x + d[0];
            int new_y = y + d[1];

            if (new_x >= 0 && new_x < board.size() &&
                new_y >= 0 && new_y < board[0].size() && 
                board[new_x][new_y] == 'O' && !is_safe[new_x][new_y]) {
                dfs(new_x, new_y, board, is_safe);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        
        vector<vector<bool>> is_safe(board.size(), vector<bool> (board[0].size(), false));

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {

                if ((row == 0 || row == board.size()-1 ||
                    col == 0 || col == board[0].size()-1) &&
                    board[row][col] == 'O' && !is_safe[row][col]
                ) {
                    dfs(row, col, board, is_safe);
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (!is_safe[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};