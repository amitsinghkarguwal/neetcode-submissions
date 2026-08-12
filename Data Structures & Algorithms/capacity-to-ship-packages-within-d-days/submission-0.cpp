#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;
        
        for (int w : weights) {
            left = max(left, w); 
            right += w;          // The ship could theoretically hold everything in 1 day
        }

        int result = right; 
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            int our_days = 1; // Start on day 1
            int current_weight = 0;
            
            for (int i : weights) {

                if (current_weight + i > mid) {
                    our_days++;
                    current_weight = i;
                } else {
                    current_weight += i; 
                }
            }
            
            if (our_days > days) {
                // Took too long. The ship is too small, we must increase capacity.
                left = mid + 1;
            } else {
                result = mid;
                right = mid - 1;
            }
        }
        
        return result;
    }
};