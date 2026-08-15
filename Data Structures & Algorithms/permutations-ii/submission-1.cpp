class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        
        // Step 1: Sort the array to group duplicates
        sort(nums.begin(), nums.end());
        
        // Step 2: Start backtracking
        backtrack(nums, visited, current, result);
        
        return result;
    }

private:
    void backtrack(const vector<int>& nums, vector<bool>& visited, 
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: If current permutation is the same size as nums, we're done
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Recursive case: Try adding unused numbers
        for (int i = 0; i < nums.size(); ++i) {
            // Skip if the number is already used in this permutation
            if (visited[i]) continue;
            
            // PRUNING CONDITION:
            // Skip if it's a duplicate AND the previous identical number was not used.
            // This prevents generating identical permutations at the same depth.
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue; 
            }
            
            // Choose
            visited[i] = true;
            current.push_back(nums[i]);
            
            // Explore
            backtrack(nums, visited, current, result);
            
            // Un-choose (Backtrack)
            current.pop_back();
            visited[i] = false;
        }
    }
};