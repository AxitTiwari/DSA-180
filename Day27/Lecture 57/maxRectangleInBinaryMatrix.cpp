#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    vector<int> nextSmallerElement(vector<int>& arr, int n) {

        stack<int> s;
        s.push(-1);

        // index of next smaller elements
        vector<int> ans(n);

        for (int i = n-1; i >= 0; i--) {

            int curr = arr[i];

            // trim the stack until found the smaller element
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr, int n) {

        stack<int> s;
        s.push(-1);

        // index of next smaller elements
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            int curr = arr[i];

            // trim the stack until found the smaller element
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;

        for (int i = 0; i < n; i++) {

            int l = heights[i];

            if (next[i] == -1) next[i] = n;
            int b = next[i] - prev[i] - 1;

            int newArea = l * b;

            area = max(area, newArea);
        }
        return area;
    }
    
  public:
    int maxArea(vector<vector<int>> &mat) {
        // code here
        
        if (mat.empty() || mat[0].empty()) return 0; 
        
        // ---------compute area for first row-----------
        int area = largestRectangleArea(mat[0]);
        
        for (int i = 1; i < mat.size(); i++) {
            
            for (int j = 0; j < mat[0].size(); j++) {
                
                // ----compute area-----
                if (mat[i][j] != 0) {
                    mat[i][j] += mat[i-1][j];
                }
                else {
                    mat[i][j] = 0;
                }
            }
            
            area = max(area, largestRectangleArea(mat[i]));
        }
        return area;
    }
};