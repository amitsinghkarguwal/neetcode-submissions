#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() < 2) {
            return arr.size();
        }
        
        int increase = 1;
        int decrease = 1;
        int max_len = 1;
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                // We just went UP. Build off the previous DOWN streak.
                increase = decrease + 1;
                decrease = 1; // Reset the DOWN streak
            } 
            else if (arr[i] < arr[i - 1]) {
                // We just went DOWN. Build off the previous UP streak.
                decrease = increase + 1;
                increase = 1; // Reset the UP streak
            } 
            else {
                // The numbers are equal. The turbulence flatlines.
                increase = 1;
                decrease = 1;
            }
            
            // Update the global maximum length found so far
            max_len = max({max_len, increase, decrease});
        }
        
        return max_len;
    }
};