#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& board) {

        unordered_set<char> us;
        for (int k = i; k < i+3; k++) {
            for (int l = j; l < j+3; l++) {

                if (board[k][l] == '.') continue;

                if (us.find(board[k][l]) != us.end()) return false;

                us.insert(board[k][l]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i = 0; i < 9; i++) {

            unordered_set<char> row;
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') continue;

                if (row.find(board[i][j]) != row.end()) return false;

                row.insert(board[i][j]);
            }
        }

        for (int i = 0; i < 9; i++) {

            unordered_set<char> col;
            for (int j = 0; j < 9; j++) {

                if (board[j][i] == '.') continue;

                if (col.find(board[j][i]) != col.end()) return false;

                col.insert(board[j][i]);
            }
        }

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (i % 3 == 0 && j % 3 == 0)
                    if (!solve(i, j, board)) return false;
            }
        }
        return true;
    }
};