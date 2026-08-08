class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        
        // Pass 1: Count how many 0s, 1s, and 2s exist
        for (int num : nums) {
            if (num == 0) count0++;
            else if (num == 1) count1++;
            else count2++;
        }
        
        // Pass 2: Overwrite the array based on the counts
        int i = 0;
        while (count0 > 0) { nums[i++] = 0; count0--; }
        while (count1 > 0) { nums[i++] = 1; count1--; }
        while (count2 > 0) { nums[i++] = 2; count2--; }
    }
};