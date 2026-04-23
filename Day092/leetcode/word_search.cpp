// https://leetcode.com/problems/word-search/submissions/1979366624

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(vector<vector<char>>& board, int x, int y, string word, int i) {

        if (i == word.length()) return true;

        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[i])
            return false;

        char temp = board[x][y];
        board[x][y] = '#'; // marked
        bool found = dfs(board, x+1, y, word, i+1) ||
                     dfs(board, x-1, y, word, i+1) ||
                     dfs(board, x, y+1, word, i+1) ||
                     dfs(board, x, y-1, word, i+1);
                    
        board[x][y] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};