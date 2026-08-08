using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;               // Pointer for 0s
        int mid = 0;               // Current element pointer
        int high = nums.size() - 1; // Pointer for 2s
        
        // Traverse the array until mid crosses high
        while (mid <= high) {
            if (nums[mid] == 0) {
                // If we find a 0, swap it to the 'low' boundary
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                // If we find a 1, it's already in the middle, just move on
                mid++;
            } 
            else if (nums[mid] == 2) {
                // If we find a 2, swap it to the 'high' boundary
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};