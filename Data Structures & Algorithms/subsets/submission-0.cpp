#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        
        dfs(0, nums, subset, res);
        
        return res;
    }

private:
    void dfs(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {
        // Base Case: If we've considered all elements
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        // Decision to include nums[i]
        subset.push_back(nums[i]);
        dfs(i + 1, nums, subset, res);

        // Decision NOT to include nums[i] (Backtracking)
        subset.pop_back();
        dfs(i + 1, nums, subset, res);
    }
};