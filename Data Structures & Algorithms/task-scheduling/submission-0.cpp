#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 1. Count frequencies of each task
        unordered_map<char, int> counts;
        for (char task : tasks) {
            counts[task]++;
        }

        // 2. Push only frequencies into a Max-Heap
        priority_queue<int> maxHeap;
        for (auto const& pair : counts) {
            maxHeap.push(pair.second);
        }

        // 3. Queue will act as our cooldown waiting room.
        // It stores pairs of {remaining_count, time_it_becomes_available}
        queue<pair<int, int>> q;
        int time = 0;

        // 4. Simulate the process until no tasks are left in the heap or queue
        while (!maxHeap.empty() || !q.empty()) {
            time++;

            // Process the most frequent task
            if (!maxHeap.empty()) {
                int count = maxHeap.top() - 1;
                maxHeap.pop();

                // If there are still instances of this task left, put it in cooldown
                if (count > 0) {
                    q.push({count, time + n});
                }
            }

            // Check if the task at the front of the queue has finished its cooldown
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};