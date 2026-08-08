class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Map to store the frequency of prefix sums we've seen so far.
        // Key = Prefix Sum, Value = How many times we've seen it.
        unordered_map<int, int> prefixCounts;
        
        // Base case: A prefix sum of 0 has occurred exactly 1 time (an empty subarray)
        prefixCounts[0] = 1;
        
        int currentPrefixSum = 0;
        int totalSubarrays = 0;
        
        for (int num : nums) {
            // Update the running sum
            currentPrefixSum += num;
            
            // Check if removing a previous prefix sum gives us exactly 'k'
            int target = currentPrefixSum - k;
            
            if (prefixCounts.find(target) != prefixCounts.end()) {
                // Add the frequency of that previous prefix sum to our total
                totalSubarrays += prefixCounts[target];
            }
            
            // Record the current prefix sum in the map for future iterations
            prefixCounts[currentPrefixSum]++;
        }
        
        return totalSubarrays;
    }
};