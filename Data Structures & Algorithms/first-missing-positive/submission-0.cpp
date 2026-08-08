#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Place each positive integer 'x' (where 1 <= x <= n) at index 'x - 1'.
        for (int i = 0; i < n; i++) {
            // We use a while loop because the number we swap into nums[i] 
            // might also need to be swapped to its correct position.
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Scan the array to find the first index that doesn't match its expected value.
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Step 3: If all numbers from 1 to n are present, the missing number is n + 1.
        return n + 1;
    }
};