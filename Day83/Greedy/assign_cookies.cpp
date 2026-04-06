// https://leetcode.com/problems/assign-cookies/submissions/1970737437

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(vector<int>& g, vector<int>& s, int i, int j) {

        if (i >= g.size() || j >= s.size()) {
            return 0;
        }

        if (s[j] >= g[i]) {
            cout << i << " " << j << endl;
            return 1 + f(g, s, i+1, j+1);
        }
        else {
            cout << "else" << endl;
            cout << i << " " << j << endl;
            return f(g, s, i, j+1);
        }

    }

public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        // ----for mainting the order----
        // important if you approach first time -> will be confused
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // -----DP solution------
        // return f(g, s, 0, 0);

        // ------greedy solution-------
        int count = 0;
        int i = 0;
        int j = 0;
        while (i < g.size() && j < s.size()) {

            if (s[j] >= g[i]) {
                count++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return count;
    }
};