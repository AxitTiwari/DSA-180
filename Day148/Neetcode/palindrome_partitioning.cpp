// https://leetcode.com/problems/palindrome-partitioning/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        
        vector<string> par;
        dfs(0, par, s);
        return res;
    }

private:
    bool is_palindrome(string str, int s, int e) {

        while (s < e) {

            if (str[s] != str[e]) return false;
            s++;
            e--;
        }
        return true;
    }
    
    void dfs(int i, vector<string> &par, string &s) {

        if (i == s.length()) {
            res.push_back(par);
            return;
        }

        for (int j = i; j < s.length(); j++) {

            if (is_palindrome(s, i, j)) {
                par.push_back(s.substr(i, j - i + 1));
                dfs(j+1, par, s);
                par.pop_back();
            }
        }
    }

};
