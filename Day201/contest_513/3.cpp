#include <bits/stdc++.h>
using namespace std;

// TLE in last case

class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {

        vector<int> res;
        int k = 0, already_completed = 0;
        for (int t : shifts) {

            while (t > 0 && k < tasks.size()) {

                int rem = tasks[k] - already_completed;

                if (t >= rem) {
                    t -= rem;
                    k++;
                    already_completed = 0;
                }
                else {
                    already_completed += t;
                    t = 0;
                }
            }

            if (k == tasks.size()) {
                res.push_back(0);
                k = 0; 
                already_completed = 0;
            }
            else{
                res.push_back(tasks.size() - k);
            }
        }
        return res;
    }
};