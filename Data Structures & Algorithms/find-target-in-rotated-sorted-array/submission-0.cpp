#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Left sorted portion
            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1; // It is here, search left
                } else {
                    low = mid + 1;  // It's not here, must be on the right
                }
            }

            // Right sorted portion
            else {
                // ...check if the target lives in this sorted range
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;  // It is here, search right
                } else {
                    high = mid - 1; // It's not here, must be on the left
                }
            }
        }

        return -1;
    }
};