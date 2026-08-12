#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        long long right = 0;
        
        // Find the maximum single element and the total sum
        for (int num : nums) {
            left = max(left, num);
            right += num;
        }
        
        int result = right;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            int subarray_count = 1; // Start with the first subarray
            long long current_sum = 0;
            
            for (int num : nums) {
                if (current_sum + num > mid) {
                    // Exceeds allowed sum, make a cut and start a new subarray
                    subarray_count++;
                    current_sum = num;
                } else {
                    // Safely add to the current subarray
                    current_sum += num;
                }
            }
            
            if (subarray_count > k) {
                // We needed too many subarrays, the allowed sum is too small
                left = mid + 1;
            } else {
                // Valid split found! Save it and try to find a smaller maximum sum
                result = mid;
                right = mid - 1;
            }
        }
        
        return result;
    }
};