class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        // Sort trips by pickup location
        sort(trips.begin(), trips.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // {dropOff, passengers}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int passengers = 0;

        for (auto& trip : trips) {

            int count = trip[0];
            int from = trip[1];
            int to = trip[2];

            // Remove passengers whose trip has ended
            while (!pq.empty() && pq.top().first <= from) {
                passengers -= pq.top().second;
                pq.pop();
            }

            // Pick up new passengers
            passengers += count;

            if (passengers > capacity)
                return false;

            // Store this trip
            pq.push({to, count});
        }

        return true;
    }
};