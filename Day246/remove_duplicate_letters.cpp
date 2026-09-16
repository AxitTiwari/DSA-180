// https://leetcode.com/problems/remove-duplicate-letters/submissions/2143482892

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        stack<int> st;
        unordered_set<char> used;

        // complete this
        unordered_map<int, int> freq = get_freq(s);

        for (char ch : s) {

            if (used.count(ch)) {
                freq[ch]--;
                continue;
            }

            while (!st.empty() && freq[st.top()] > 1 && st.top() > ch) {
                freq[st.top()]--;
                used.erase(st.top());
                st.pop();
            }

            st.push(ch);
            used.insert(ch);
        }

        string res;
        while (!st.empty()) {

            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
private:
    unordered_map<int, int> get_freq(string s) {

        unordered_map<int, int> cnt;
        for (char ch : s) {
            cnt[ch]++;
        }
        return cnt;
    }
};