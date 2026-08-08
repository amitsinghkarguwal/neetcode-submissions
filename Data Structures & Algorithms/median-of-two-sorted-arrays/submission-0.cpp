#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // We ALWAYS do binary search on the smaller array to guarantee O(log(min(N, M)))
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();
        
        int low = 0;
        int high = x;

        while (low <= high) {
            // Partition A is exactly in the middle of our binary search bounds
            int partitionX = low + (high - low) / 2;
            
            // Partition B is calculated so the total left side = (x + y + 1) / 2
            int partitionY = (x + y + 1) / 2 - partitionX;

            // Handle edges: if partition is at the extreme end, use INT_MIN or INT_MAX
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            // Check if we found the perfect cut
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // If total length is even, median is average of the two middle elements
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } 
                // If total length is odd, the median is just the max of the left side
                else { 
                    return max(maxLeftX, maxLeftY);
                }
            } 
            // We are too far right in Array X, go left
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } 
            // We are too far left in Array X, go right
            else {
                low = partitionX + 1;
            }
        }

        return 0.0; // Should never reach here if arrays are valid
    }
};