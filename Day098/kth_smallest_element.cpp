// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/1984582464

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        std::priority_queue <int> max_heap;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {

                if (max_heap.size() < k) {
                    max_heap.push(matrix[i][j]);
                }
                else {
                    if (max_heap.top() > matrix[i][j]) {

                        max_heap.pop();
                        max_heap.push(matrix[i][j]);
                    }
                }
            }
        }
        return max_heap.top();
    }
};