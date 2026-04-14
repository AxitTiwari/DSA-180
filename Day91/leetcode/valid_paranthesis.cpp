// https://leetcode.com/problems/valid-parenthesis-string/submissions/1978516006

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool f(string& s, int i, int cnt) {

        if (i == s.length()) {
            return cnt == 0;
        }

        if (s[i] == '(') {
            return f(s, i+1, cnt+1);
        }
        else if (s[i] == ')') {
            return f(s, i+1, cnt-1);
        }
        else {
            return f(s, i+1, cnt+1) || f(s, i+1, cnt-1) || f(s, i+1, cnt);
        }
    }

    // O(N**2)
    bool mem(string& s, int i, int cnt, vector<vector<int>>& m) {

        if (cnt < 0) return false;

        if (i == s.length()) {
            return cnt == 0;
        }

        if (m[i][cnt] != -1) {
            return m[i][cnt];
        }

        if (s[i] == '(') {
            return m[i][cnt] = mem(s, i+1, cnt+1, m);
        }
        else if (s[i] == ')') {
            return m[i][cnt] = mem(s, i+1, cnt-1, m);
        }
        else {
            return m[i][cnt] = mem(s, i+1, cnt+1, m) || mem(s, i+1, cnt-1, m) || mem(s, i+1, cnt, m);
        }
    }

    // O(n)
    bool func(string s) {

        int min = 0, max = 0;
        for (char ch : s) {

            if (ch == '(') {
                min = min + 1;
                max = max + 1;
            }
            else if (ch == ')') {
                min = min - 1;
                max = max - 1;
            }
            else {
                min = min - 1;
                max = max + 1;
            }

            if (min < 0) {
                min = 0;
            }

            if (max < 0) return false;
        }
        return min == 0;
    }
public:
    bool checkValidString(string s) {

        // bool result = f(s, 0, 0);
        // return result;

        // vector<vector<int>> m(s.length()+1, vector<int> (s.length()+1, -1));
        // bool result = mem(s, 0, 0, m);
        // return result;

        return func(s);
    }
};