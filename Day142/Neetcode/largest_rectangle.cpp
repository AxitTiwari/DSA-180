// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> get_prev_smaller(vector<int> &heights) {

        int n = heights.size() - 1;

        vector<int> result(n+1);

        stack<int> s;
        for (int i = 0; i <= n; i++) {

            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            result[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return result;
    }

    vector<int> get_next_smaller(vector<int> &heights) {

        int n = heights.size() - 1;

        vector<int> result(n+1);

        stack<int> s;
        for (int i = n; i >= 0; i--) {

            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            result[i] = s.empty() ? n+1 : s.top();
            s.push(i);
        }
        return result;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> prev_smaller = get_prev_smaller(heights);
        vector<int> next_smaller = get_next_smaller(heights);

        int max_area = 0;
        for (int idx = 0; idx < heights.size(); idx++) {

            int i = prev_smaller[idx] + 1;
            int j = next_smaller[idx] - 1;

            int width = (j - i) + 1;
            int height = heights[idx];

            // cout << heights[idx] << ": " << width << " * " << height << endl;

            int area = width * height;
            max_area = max(area, max_area);
        }
        return max_area;
    }
};
