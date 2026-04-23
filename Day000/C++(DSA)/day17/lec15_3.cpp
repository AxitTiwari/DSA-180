#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int stalls[], int no_of_stalls, int no_of_cows, int possible_max_distance) {
    
    int cow_count = 1;
    int last_position = stalls[0];

    for(int i = 0; i < no_of_stalls; i++) {

        if(stalls[i] - last_position >= possible_max_distance) {

            cow_count++;

            if(cow_count == no_of_cows)
                return true;

            last_position = stalls[i];
        }

    }
    return false;
}

int main() {
    // Aggressice Cows

    int no_of_stalls;
    cout << "Enter total number of stalls: ";
    cin >> no_of_stalls;

    int no_of_cows;
    cout << "Enter the number aggressive cows: ";
    cin >> no_of_cows;

    int stalls[20];
    cout << "Enter position of each stall: ";
    for(int stall_count = 0; stall_count < no_of_stalls; stall_count++) {
        cin >> stalls[stall_count];
    }

    sort(stalls, stalls + no_of_stalls);

    int max_position_of_stall = INT32_MIN;
    int min_position_of_stall = INT32_MAX;

    for(int stall_count = 0; stall_count < no_of_stalls; stall_count++) {
        
        // cout << max_position_of_stall << " " << min_position_of_stall << endl;
        if(max_position_of_stall < stalls[stall_count]) {
            max_position_of_stall = stalls[stall_count];
        }

        if(min_position_of_stall > stalls[stall_count]) {
            min_position_of_stall = stalls[stall_count];
        }

        // cout << "stall count: " << stall_count << endl;
    }

    // cout << "max   min" << endl;
    // cout << max_position_of_stall << " " << min_position_of_stall << endl;

    int start = 0;
    int end = max_position_of_stall - min_position_of_stall;
    int mid = start + (end - start) / 2;

    int max_min_distance_of_cows = -1;

    while(start <= end) {

        // cout << start << " " << end << endl;

        if(isPossible(stalls, no_of_stalls, no_of_cows, mid)) {
            max_min_distance_of_cows = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;

        // cout << start << " " << end << endl;
    }

    cout << "Minimum maximum distance between two aggressive cow would be: " << max_min_distance_of_cows << endl;

    return 0;
}