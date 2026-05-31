// https://leetcode.com/problems/palindrome-partitioning/?envType=problem-list-v2&envId=dynamic-programming

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool is_palindrome(string str, int s, int e) {

        while (s < e) {

            if (str[s] != str[e]) return false;
            s++;
            e--;
        }
        return true;
    }

    void func(int i, string &s, vector<string> &sub, vector<vector<string>> &output) {

        if (i >= s.length()) {
            output.push_back(sub);
            return;
        }

        for (int j = i; j < s.length(); j++) {
        
            if (is_palindrome(s, i, j)) {
                sub.push_back(s.substr(i, j - i + 1));
                func(j+1, s, sub, output);
                sub.pop_back();
            }
        }
    }   

public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> output;
        vector<string> sub;
        func(0, s, sub, output);
        return output;
    }
};