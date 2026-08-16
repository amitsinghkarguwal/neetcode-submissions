#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Step 1: Sort meetings strictly by start time
        sort(meetings.begin(), meetings.end());

        // Min-heap to store available rooms by their lowest index
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }

        // Min-heap to store busy rooms: pair of {end_time, room_index}
        // Use long long for end times because delays can cause times to exceed 32-bit integer limits
        typedef pair<long long, int> pii;
        priority_queue<pii, vector<pii>, greater<pii>> busy;

        // Array to count the number of meetings each room hosts
        vector<int> counts(n, 0);

        // Step 2: Process each meeting
        for (const auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];

            // Free up rooms that finished before or exactly when the current meeting starts
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                // An available room exists. Assign it to the room with the lowest index.
                int room = available.top();
                available.pop();
                
                busy.push({end, room});
                counts[room]++;
            } else {
                // No room is available, so the meeting is delayed.
                // Pick the room that frees up the earliest.
                auto [free_time, room] = busy.top();
                busy.pop();
                
                // The new end time is the time the room became free PLUS the duration of the meeting
                long long duration = end - start;
                busy.push({free_time + duration, room});
                counts[room]++;
            }
        }

        // Step 3: Find the room with the most meetings
        int max_meetings = 0;
        int best_room = 0;
        
        for (int i = 0; i < n; ++i) {
            // Using strictly greater '>' naturally breaks ties by picking the lower index, 
            // since we iterate from room 0 upwards.
            if (counts[i] > max_meetings) {
                max_meetings = counts[i];
                best_room = i;
            }
        }

        return best_room;
    }
};