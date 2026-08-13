class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;
        
        // Variables for Kadane's Max
        int max_sum = nums[0];
        int curr_max = 0;
        
        // Variables for Kadane's Min
        int min_sum = nums[0];
        int curr_min = 0;
        
        for (int num : nums) {
            // Track the total sum of the array
            total_sum += num;
            
            // Standard Kadane's for Maximum Subarray
            curr_max = max(curr_max + num, num);
            max_sum = max(max_sum, curr_max);
            
            // Inverted Kadane's for Minimum Subarray
            curr_min = min(curr_min + num, num);
            min_sum = min(min_sum, curr_min);
        }
        
        // Edge Case: If all numbers are negative, max_sum will be less than 0.
        // If we did (total_sum - min_sum) here, it would return 0, which is invalid.
        if (max_sum < 0) {
            return max_sum;
        }
        
        // Otherwise, return the max of Scenario A (normal) and Scenario B (wrap-around)
        return max(max_sum, total_sum - min_sum);
    }
};