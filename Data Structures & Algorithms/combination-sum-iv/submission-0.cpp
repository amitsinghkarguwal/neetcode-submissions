#include <vector>

using namespace std;

class Solution {
public:
    // Our DP state is just the remaining target!
    int solve(vector<int>& nums, int target, vector<unsigned int>& dp) {
        
        // 1. BASE CASE: If target hits exactly 0, we found 1 valid permutation!
        if (target == 0) {
            return 1;
        }
        
        // If target goes below 0, this path is a dead end.
        if (target < 0) {
            return 0;
        }
        
        // 2. MEMORY CHECK
        if (dp[target] != -1) {
            return dp[target];
        }
        
        unsigned int total_ways = 0;
        
        // 3. EXPLORE: To get permutations, we loop through the ENTIRE array every single time.
        for (int i = 0; i < nums.size(); i++) {
            
            // If the current number can fit in our remaining target
            if (nums[i] <= target) {
                // Add the number of ways we can reach 0 from the new target
                total_ways += solve(nums, target - nums[i], dp);
            }
        }
        
        // 4. CACHE AND RETURN
        return dp[target] = total_ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        // 1D DP table initialized to -1. Size is target + 1.
        vector<unsigned int> dp(target + 1, -1);
        
        return solve(nums, target, dp);
    }
};