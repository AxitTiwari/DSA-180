
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(string skill, string station) {

        vector<int> left = first(skill, station);
        vector<int> right = last(skill, station);

        int m_gap = 0;
        for (int i = 1; i < right.size(); i++) {

            int gap = right[i] - left[i-1];

            if (gap > m_gap) {
                m_gap = gap;
            }
        }
        return m_gap;
    }

private:
    vector<int> first(string skill, string station) {

        vector<int> left;
        int idx = 0;
        for (int s : skill) {

            for (int i = idx; i < station.length(); i++, idx++) {
                if (station[i] == s) {
                    left.push_back(i);
                    idx = i + 1;
                    break;
                }
            }
        }
        return left;
    }
    vector<int> last(string skill, string station) {

        vector<int> right;
        int idx = station.length()-1;
        for (int i = skill.length()-1; i >= 0; i--) {

            char s = skill[i];
            for (int i = idx; i >= 0; i--, idx--) {
                if (station[i] == s) {
                    right.push_back(i);
                    idx = i - 1;
                    break;
                }
            }
        }

        reverse(right.begin(), right.end());
        return right;
    }
};