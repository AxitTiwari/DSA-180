#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {

            pq.push(num);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        priority_queue<int> max_heap;
        while (!pq.empty()) {

            max_heap.push(pq.top());
            pq.pop();
        }

        long long sum = 0;
        while (!max_heap.empty()) {

            int num = max_heap.top();
            max_heap.pop();

            sum = mul > 0 ? sum + (long long) num * mul : sum + num;
            mul = mul - 1;
        }
        return sum;
    }
};