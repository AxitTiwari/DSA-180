#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<bool> is_prime;

    // store all primes between range
    void build(int max_n) {
        
        is_prime.assign(max_n + 1, true);

        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= max_n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= max_n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
    // bool is_prime(int num) {
    //     if (num <= 1) return false;
    //     if (num == 2) return true;
    
    //     for (int i = 2; i * i <= num; i++) {
    //         if (num % i == 0) return false;
    //     }
    //     return true;
    // }

    int solve(int num, bool is_even_index) {

        // cout << "num: " << num << endl;

        int operations = 0;
        if (is_even_index) {
            while (!is_prime[num]) {
                num += 1;
                operations++;
            }
        }
        else {
            while (is_prime[num]) {
                num++;
                operations++;
            }
        }

        // cout << operations << " -- " << num << endl;
        return operations;
    }
    
public:
    int minOperations(vector<int>& nums) {

        int max_n = 300000;
        build(max_n);

        int min_operation = 0;
        int index = 0;
        for (int num : nums) {

            bool is_even_index = (index % 2 == 0) ? true : false;
            min_operation += solve(num, is_even_index);
            index++;
        }

        return min_operation;
    }
};