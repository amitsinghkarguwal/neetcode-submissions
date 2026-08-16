#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        vector<int> starts;
        vector<int> ends;
        starts.reserve(intervals.size());
        ends.reserve(intervals.size());

        // Extract the start and end times
        for (const auto& interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        // Sort both arrays independently
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int maxRooms = 0;
        int currentRooms = 0;
        
        int s = 0; // Pointer for start times
        int e = 0; // Pointer for end times

        // Iterate through the schedule
        while (s < intervals.size()) {
            // A meeting is starting before the current earliest meeting ends
            if (starts[s] < ends[e]) {
                currentRooms++;
                maxRooms = max(maxRooms, currentRooms);
                s++;
            } 
            // A meeting has ended, freeing up a room
            else {
                currentRooms--;
                e++;
            }
        }

        return maxRooms;
    }
};