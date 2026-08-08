#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Set up the three pointers starting from the back
        int p1 = m - 1;             // Last real element in nums1
        int p2 = n - 1;             // Last element in nums2
        int p = m + n - 1;          // The very last empty slot in nums1

        // We only need to keep looping as long as there are elements in nums2.
        // (If nums2 runs out, the remaining elements in nums1 are already sorted in place!)
        while (p2 >= 0) {
            // If p1 is still valid and the nums1 element is strictly greater
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } 
            // Otherwise, the nums2 element is greater (or p1 ran out)
            else {
                nums1[p] = nums2[p2];
                p2--;
            }

            p--;
        }
    }
};