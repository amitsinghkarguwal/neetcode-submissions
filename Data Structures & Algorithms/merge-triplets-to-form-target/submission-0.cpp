#include <vector>

using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // Track if we have found the exact target value for each position 
        // across all of our "safe" triplets.
        bool found_x = false;
        bool found_y = false;
        bool found_z = false;

        for (const auto& triplet : triplets) {
            // 1. The Greedy Filter: Ignore any triplet that would overshoot our target
            if (triplet[0] > target[0] || 
                triplet[1] > target[1] || 
                triplet[2] > target[2]) {
                continue; // Skip this toxic triplet
            }

            // 2. If it is safe, check if it contains any of our exact target numbers
            if (triplet[0] == target[0]) found_x = true;
            if (triplet[1] == target[1]) found_y = true;
            if (triplet[2] == target[2]) found_z = true;

            // 3. Early Exit Optimization: If we've found all three, we win!
            if (found_x && found_y && found_z) {
                return true;
            }
        }

        // Return true only if we found all three required pieces
        return found_x && found_y && found_z;
    }
};