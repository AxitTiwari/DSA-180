// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/?envType=daily-question&envId=2026-06-30

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int res = 0;
        deque<int> dq;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {

            dq.push_back(s[i]);
            mp[s[i]] += 1;

            if (dq.size() >= 3) {

                while (mp['a'] and mp['b'] and mp['c']) {
                    res += s.length() - i;

                    cout << res << " ";
                    mp[dq.front()] -= 1;
                    dq.pop_front();
                }
            }
        }
        return res;
    }
};