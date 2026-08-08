#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize to the first element to handle arrays with all negative numbers edge case banta hai yaha safely
        int maxSum = nums[0]; 
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // 1. If our running sum is negative, throw it away. Start fresh.
            if (currentSum < 0) {
                currentSum = 0;
            }

            // 2. Add the current number to our running total
            currentSum += nums[i];

            // 3. Update the maximum score we've seen so far
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }

        return maxSum;
    }
};