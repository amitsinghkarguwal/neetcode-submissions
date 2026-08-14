#include <vector>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> stops(1001, 0);
        
        for (const auto& trip : trips) {
            int num_passengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            
            stops[from] += num_passengers; // Passengers get in
            stops[to] -= num_passengers;   // Passengers get out
        }
        
        int current_passengers = 0;
        
        for (int i = 0; i <= 1000; i++) {
            current_passengers += stops[i];

            if (current_passengers > capacity) {
                return false;
            }
        }

        return true;
    }
};