// https://leetcode.com/contest/weekly-contest-514/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {

        priority_queue<int> pq_dis;
        for (int discount : discounts) pq_dis.push(discount);

        double total = 0;
        priority_queue<int> pq_price;
        for (int i = 0; i < prices.size(); i++) {
            pq_price.push(prices[i]);
            total += prices[i];
        }

        while (!pq_dis.empty() && !pq_price.empty()) {

            int dis = pq_dis.top();
            pq_dis.pop();

            int price = pq_price.top();
            pq_price.pop();

            total -= price;

            double new_price = (double) price * (100 - dis) / 100;
            total += new_price;
        }
        return total;
    }
};