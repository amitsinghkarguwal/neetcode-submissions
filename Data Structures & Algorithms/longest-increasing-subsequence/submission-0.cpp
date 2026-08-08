//approach 2, momo+rec

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int dfs(vector<int>& nums, int i, vector<int>& memo) {
        
        // 1. MEMORY CHECK
        if (memo[i] != -1) {
            return memo[i];
        }
        
        int max_len = 1; // A single number is always a valid sequence of length 1
        
        // 2. EXPLORE: Look at every number to the right of our current index
        for (int j = i + 1; j < nums.size(); j++) {
            
            // If the future number is strictly greater, it's a valid next step!
            if (nums[j] > nums[i]) {
                // Take 1 (our current number) + the longest path from j
                max_len = max(max_len, 1 + dfs(nums, j, memo));
            }
        }
        
        // 3. CACHE & RETURN
        return memo[i] = max_len;
    }

    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int n = nums.size();
        

        vector<int> memo(n, -1);

        int global_max = 1;
        
        for (int i = 0; i < n; i++) {
            global_max = max(global_max, dfs(nums, i, memo));
        }
        
        return global_max;
    }
};