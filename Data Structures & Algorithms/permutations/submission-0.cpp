#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        // Keep track of which elements are currently in our path
        vector<bool> used(nums.size(), false);
        
        backtrack(nums, path, used, res);
        return res;
    }

private:
    void backtrack(const vector<int>& nums, vector<int>& path, vector<bool>& used, vector<vector<int>>& res) {
        // Base Case: If the path length equals nums length, we have a complete permutation
        if (path.size() == nums.size()) {
            res.push_back(path); // push_back makes a copy of 'path' automatically in C++
            return;
        }
        
        // Recursive Step: Try all possible numbers
        for (int i = 0; i < nums.size(); ++i) {
            // Pruning: O(1) check to skip numbers already in the current permutation
            if (used[i]) {
                continue;
            }
            
            // 1. Choose
            used[i] = true;
            path.push_back(nums[i]);
            
            // 2. Explore
            backtrack(nums, path, used, res);
            
            // 3. Un-choose (Backtrack)
            path.pop_back();
            used[i] = false;
        }
    }
};