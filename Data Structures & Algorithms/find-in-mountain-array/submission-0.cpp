/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        // Step 1: Find the Peak Index
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                // We are climbing up, the peak must be to the right
                left = mid + 1;
            } else {
                // We are falling down, the peak is at mid or to the left
                right = mid;
            }
        }
        
        int peak = left;
        
        // Step 2: Search the Left Ascending Slope
        left = 0;
        right = peak;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_val = mountainArr.get(mid);
            
            if (mid_val == target) {
                return mid;
            } else if (mid_val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Step 3: Search the Right Descending Slope
        left = peak + 1;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_val = mountainArr.get(mid);
            
            if (mid_val == target) {
                return mid;
            } else if (mid_val > target) {
                // CAUTION: The array is descending! 
                // If mid is larger than target, the target must be further to the right.
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Target was not found on either side
        return -1;
    }
};