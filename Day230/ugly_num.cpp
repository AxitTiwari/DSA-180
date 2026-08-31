// https://leetcode.com/submissions/detail/2126241361/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {

        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);

        unordered_set<long> set;
        set.insert(1);

        long ugly = 1;
        while (n--) {

            ugly = pq.top();
            pq.pop();

            long n1 = ugly * 2;
            long n2 = ugly * 3;
            long n3 = ugly * 5;

            if (set.insert(n1).second) pq.push(n1);

            if (set.insert(n2).second) pq.push(n2);

            if (set.insert(n3).second) pq.push(n3);
        }
        return (int)ugly;
    }
};