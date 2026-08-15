class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums) sum += num;
        
        // Base mathematical impossibility checks
        if (sum % k != 0 || nums.empty()) return false;
        
        int target = sum / k;
        
        // PRUNING 1: Sort descending to place large elements first
        sort(nums.rbegin(), nums.rend());
        
        // If the largest single element is bigger than the target, impossible
        if (nums[0] > target) return false; 
        
        vector<bool> visited(nums.size(), false);
        return backtrack(nums, visited, 0, k, 0, target);
    }

private:
    bool backtrack(const vector<int>& nums, vector<bool>& visited, 
                   int startIndex, int k, int currentSum, int target) {
        
        // Base case: If we successfully formed k-1 subsets, 
        // the remaining elements are guaranteed to sum to the target.
        if (k == 1) return true;
        
        // If the current subset is full, start the next one
        if (currentSum == target) {
            return backtrack(nums, visited, 0, k - 1, 0, target);
        }
        
        // Try adding remaining numbers to the current subset
        for (int i = startIndex; i < nums.size(); i++) {
            // Skip used numbers or those that would overflow the subset
            if (visited[i] || currentSum + nums[i] > target) {
                continue;
            }
            
            // PRUNING 2: Duplicate skipping
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            
            // Choose
            visited[i] = true;
            
            // Explore
            if (backtrack(nums, visited, i + 1, k, currentSum + nums[i], target)) {
                return true;
            }
            
            // Un-choose (Backtrack)
            visited[i] = false;
            
            // PRUNING 3 (CRITICAL): The "Empty Subset" Optimization
            // If we are starting a fresh subset (currentSum == 0) and the branch failed,
            // there is no point trying to put this number in a different subset.
            if (currentSum == 0) {
                return false; 
            }
        }
        
        return false;
    }
};