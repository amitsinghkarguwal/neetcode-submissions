#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // Sort intervals based on their start times.
        // C++ vectors sort lexicographically by default, so it automatically 
        // sorts by the first element (start time).
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        // Start by adding the very first interval
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            // Get a reference to the last added interval in our result list
            auto& lastInterval = res.back();

            // Check for overlap: current interval starts before or when the last one ends
            if (intervals[i][0] <= lastInterval[1]) {
                // Merge by taking the furthest end time
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            } else {
                // No overlap, add it as a new distinct interval
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};