#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        // Sort intervals by their start times
        sort(intervals.begin(), intervals.end());

        int removals = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            // Case 1: Overlap detected
            if (intervals[i][0] < prevEnd) {
                removals++;
                // Greedily keep the interval that ends earlier
                prevEnd = min(prevEnd, intervals[i][1]);
            } 
            // Case 2: No overlap
            else {
                prevEnd = intervals[i][1];
            }
        }

        return removals;
    }
};