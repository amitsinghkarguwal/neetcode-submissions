#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        
        // Sort in DESCENDING order (closest to target first)
        sort(cars.rbegin(), cars.rend());
        

        stack<double> st;    // The stack will store the arrival times of the fleet leaders
        
        for (int i = 0; i < n; i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            
            // If the stack is empty, OR this car takes longer than the fleet ahead of it,
            // it forms a new fleet!
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }
        
        return st.size();
    }
};
