// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/submissions/1999680475

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        // avialable ingredients
        unordered_map<string, bool> is_avialable;

        for (auto s : supplies) {
            is_avialable[s] = true;
        }

        vector<string> ans;
        bool progress = true;

        unordered_map<string, int> made;
        while (progress) {

            progress = false;
            for (int i = 0; i < recipes.size(); i++) {

                if (made[recipes[i]]) continue;

                bool can_create = true;
                for (auto ingredient : ingredients[i]) {
                    if (!is_avialable[ingredient]) {
                        can_create = false;
                        break;
                    }
                }

                if (can_create) {
                    ans.push_back(recipes[i]);
                    is_avialable[recipes[i]] = true;
                    made[recipes[i]] = true;
                    progress = true;
                }
            }
        }
        return ans;
    }
};