#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {

        // triangle inequality theroem
        sort(sides.begin(), sides.end());

        if (!(sides[0] + sides[1] > sides[2])) {
            return {};
        }

        vector<double> angles(3);
        find_angles(sides, angles);
        return angles;
    }
private:
    void find_angles(vector<int>& sides, vector<double>& angles) {

        int a = sides[0];
        int b = sides[1];
        int c = sides[2];
        
        double A = acos((double)(b*b + c*c - a*a) / (2*b*c));
        double B = acos((double)(a*a + c*c - b*b) / (2*a*c));
        double C = acos((double)(a*a + b*b - c*c) / (2*a*b));
    
        // convert to degrees
        angles[0] = A * 180.0 / M_PI;
        angles[1] = B * 180.0 / M_PI;
        angles[2] = C * 180.0 / M_PI;

        sort(angles.begin(), angles.end());
    }
};