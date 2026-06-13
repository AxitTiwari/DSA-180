// https://leetcode.com/problems/surrounded-regions/submissions/2030403763

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        vector<vector<bool>> can_edit(board.size(), vector<bool> (board[0].size(), true));
        for (int c = 0; c < board[0].size(); c++) {
            dfs(0, c, board, can_edit);
        }

        for (int c = 0; c < board[0].size(); c++) {
            dfs(board.size()-1, c, board, can_edit);
        }

        for (int r = 0; r < board.size(); r++) {
            dfs(r, 0, board, can_edit);
        }

        for (int r = 0; r < board.size(); r++) {
            dfs(r, board[0].size()-1, board, can_edit);
        }

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {

                if (board[r][c] == 'O' && can_edit[r][c]) {
                    board[r][c] = 'X';
                }
            }
        }
    }

private:
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>> &can_edit) {

        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == 'X' || !can_edit[x][y]) return;

        can_edit[x][y] = false;

        dfs(x+1, y, board, can_edit);
        dfs(x, y+1, board, can_edit);
        dfs(x-1, y, board, can_edit);
        dfs(x, y-1, board, can_edit);
    }
};