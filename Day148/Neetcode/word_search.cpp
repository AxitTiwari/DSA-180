// https://leetcode.com/problems/word-search/submissions/2028561818/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(i, j, 0, word, board)) return true;
            }
        }
        return false;
    }
private:

    bool dfs(int x, int y, int i, string &word, vector<vector<char>>& board) {

        if (i == word.size()) return true;

        if (x >= board.size() || x < 0 || y < 0 || y >= board[0].size()) return false;

        if (board[x][y] != word[i]) {
            return false;
        }

        char ch = board[x][y];
        board[x][y] = '#';
        bool found = dfs(x+1, y, i+1, word, board) ||
                dfs(x, y+1, i+1, word, board) ||
                dfs(x-1, y, i+1, word, board) ||
                dfs(x, y-1, i+1, word, board);
        board[x][y] = ch;
        return found;
    }
};