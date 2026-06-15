https://leetcode.com/problems/n-queens-ii/?envType=problem-list-v2&envId=w4wg4g43

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int res;
    int totalNQueens(int n) {
        
        vector<vector<int>> board(n, vector<int> (n, 0));
        func(0, board);
        return res;
    }

private:
    bool is_safe(int r, int c, vector<vector<int>> &board) {


        int x = r;
        int y = c;

        while (y >= 0) {

            if (board[x][y] == 1) return false;
            y--;
        }

        x = r, y = c;

        while (x >= 0 && y >= 0) {

            if (board[x][y] == 1) return false;

            x--, y--;
        }

        x = r, y = c;

        int n = board.size();
        while (x < n && y >= 0) {

            if (board[x][y] == 1) return false;

            x++, y--;
        }

        return true;
    }

    void func(int col, vector<vector<int>> &board) {

        if (col == board.size()) {
            res += 1;
            return;
        }

        for (int row = 0; row < board.size(); row++) {

            if (is_safe(row, col, board)) {

                // cout << "safe" << endl;
                board[row][col] = 1;
                func(col+1, board);

                board[row][col] = 0;
            }
        }
    }

};
