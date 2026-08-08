class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Pointer for where to place the next non-val element
        
        // Iterate through the entire array
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is NOT the value we want to remove
            if (nums[i] != val) {
                // Place it at the 'k' index and increment 'k'
                nums[k] = nums[i];
                k++;
            }
        }
        
        // 'k' now represents the number of valid elements left
        return k; 
    }
};